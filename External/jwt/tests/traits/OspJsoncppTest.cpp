#include "jwt-cpp/traits/open-source-parsers-jsoncpp/traits.h"

#include <gtest/gtest.h>

TEST(OspJsoncppTest, BasicClaims) {
	const auto string = jwt::basic_claim<jwt::traits::open_source_parsers_jsoncpp>(
		jwt::traits::open_source_parsers_jsoncpp::string_type("string"));
	ASSERT_EQ(string.get_type(), jwt::json::type::string);

	const auto array = jwt::basic_claim<jwt::traits::open_source_parsers_jsoncpp>(
		std::set<jwt::traits::open_source_parsers_jsoncpp::string_type>{"string", "string"});
	ASSERT_EQ(array.get_type(), jwt::json::type::array);

	const auto integer = jwt::basic_claim<jwt::traits::open_source_parsers_jsoncpp>(159816816);
	ASSERT_EQ(integer.get_type(), jwt::json::type::integer);
}

TEST(OspJsoncppTest, AudienceAsString) {
	jwt::traits::open_source_parsers_jsoncpp::string_type token =
		"eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJhdWQiOiJ0ZXN0In0.WZnM3SIiSRHsbO3O7Z2bmIzTJ4EC32HRBKfLznHhrh4";
	auto decoded = jwt::decode<jwt::traits::open_source_parsers_jsoncpp>(token);

	ASSERT_TRUE(decoded.has_algorithm());
	ASSERT_TRUE(decoded.has_type());
	ASSERT_FALSE(decoded.has_content_type());
	ASSERT_FALSE(decoded.has_key_id());
	ASSERT_FALSE(decoded.has_issuer());
	ASSERT_FALSE(decoded.has_subject());
	ASSERT_TRUE(decoded.has_audience());
	ASSERT_FALSE(decoded.has_expires_at());
	ASSERT_FALSE(decoded.has_not_before());
	ASSERT_FALSE(decoded.has_issued_at());
	ASSERT_FALSE(decoded.has_id());

	ASSERT_EQ("HS256", decoded.get_algorithm());
	ASSERT_EQ("JWT", decoded.get_type());
	auto aud = decoded.get_audience();
	ASSERT_EQ(1, aud.size());
	ASSERT_EQ("test", *aud.begin());
}

TEST(OspJsoncppTest, SetArray) {
	std::vector<int64_t> vect = {100, 20, 10};
	auto token = jwt::create<jwt::traits::open_source_parsers_jsoncpp>()
					 .set_payload_claim(
						 "test", jwt::basic_claim<jwt::traits::open_source_parsers_jsoncpp>(vect.begin(), vect.end()))
					 .sign(jwt::algorithm::none{});
	ASSERT_EQ(token, "eyJhbGciOiJub25lIn0.eyJ0ZXN0IjpbMTAwLDIwLDEwXX0.");
}

TEST(OspJsoncppTest, SetObject) {
	std::istringstream iss{"{\"api-x\": [1]}"};
	jwt::basic_claim<jwt::traits::open_source_parsers_jsoncpp> object;
	iss >> object;
	ASSERT_EQ(object.get_type(), jwt::json::type::object);

	auto token = jwt::create<jwt::traits::open_source_parsers_jsoncpp>()
					 .set_payload_claim("namespace", object)
					 .sign(jwt::algorithm::hs256("test"));
	ASSERT_EQ(token,
			  "eyJhbGciOiJIUzI1NiJ9.eyJuYW1lc3BhY2UiOnsiYXBpLXgiOlsxXX19.F8I6I2RcSF98bKa0IpIz09fRZtHr1CWnWKx2za-tFQA");
}

TEST(OspJsoncppTest, VerifyTokenHS256) {
	jwt::traits::open_source_parsers_jsoncpp::string_type token =
		"eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXUyJ9.eyJpc3MiOiJhdXRoMCJ9.AbIJTDMFc7yUa5MhvcP03nJPyCPzZtQcGEp-zWfOkEE";

	const auto decoded_token = jwt::decode<jwt::traits::open_source_parsers_jsoncpp>(token);
	const auto verify = jwt::verify<jwt::traits::open_source_parsers_jsoncpp>()
							.allow_algorithm(jwt::algorithm::hs256{"secret"})
							.with_issuer("auth0");
	verify.verify(decoded_token);
}

TEST(OspJsoncppTest, VerifyTokenExpirationValid) {
	const auto token = jwt::create<jwt::traits::open_source_parsers_jsoncpp>()
						   .set_issuer("auth0")
						   .set_issued_at(std::chrono::system_clock::now())
						   .set_expires_at(std::chrono::system_clock::now() + std::chrono::seconds{3600})
						   .sign(jwt::algorithm::hs256{"secret"});

	const auto decoded_token = jwt::decode<jwt::traits::open_source_parsers_jsoncpp>(token);
	const auto verify = jwt::verify<jwt::traits::open_source_parsers_jsoncpp>()
							.allow_algorithm(jwt::algorithm::hs256{"secret"})
							.with_issuer("auth0");
	verify.verify(decoded_token);
}

TEST(OspJsoncppTest, VerifyTokenExpirationInValid) {
	const auto token = jwt::create<jwt::traits::open_source_parsers_jsoncpp>()
						   .set_issuer("auth0")
						   .set_issued_now()
						   .set_expires_in(std::chrono::seconds{3600})
						   .sign(jwt::algorithm::hs256{"secret"});

	const auto decoded_token = jwt::decode<jwt::traits::open_source_parsers_jsoncpp>(token);
	const auto verify = jwt::verify<jwt::traits::open_source_parsers_jsoncpp>()
							.allow_algorithm(jwt::algorithm::hs256{"secret"})
							.with_issuer("auth0");
	verify.verify(decoded_token);
}

TEST(OspJsoncppTest, VerifyTokenExpired) {
	const auto token = jwt::create<jwt::traits::open_source_parsers_jsoncpp>()
						   .set_issuer("auth0")
						   .set_issued_at(std::chrono::system_clock::now() - std::chrono::seconds{3601})
						   .set_expires_at(std::chrono::system_clock::now() - std::chrono::seconds{1})
						   .sign(jwt::algorithm::hs256{"secret"});

	const auto decoded_token = jwt::decode<jwt::traits::open_source_parsers_jsoncpp>(token);
	const auto verify = jwt::verify<jwt::traits::open_source_parsers_jsoncpp>()
							.allow_algorithm(jwt::algorithm::hs256{"secret"})
							.with_issuer("auth0");
	ASSERT_THROW(verify.verify(decoded_token), jwt::error::token_verification_exception);

	std::error_code ec;
	ASSERT_NO_THROW(verify.verify(decoded_token, ec));
	ASSERT_TRUE(!(!ec));
	ASSERT_EQ(ec.category(), jwt::error::token_verification_error_category());
	ASSERT_EQ(ec.value(), static_cast<int>(jwt::error::token_verification_error::token_expired));
}

TEST(OspJsoncppTest, VerifyArray) {
	jwt::traits::open_source_parsers_jsoncpp::string_type token = "eyJhbGciOiJub25lIn0.eyJ0ZXN0IjpbMTAwLDIwLDEwXX0.";
	const auto decoded_token = jwt::decode<jwt::traits::open_source_parsers_jsoncpp>(token);

	std::vector<int64_t> vect = {100, 20, 10};
	jwt::basic_claim<jwt::traits::open_source_parsers_jsoncpp> array_claim(vect.begin(), vect.end());
	const auto verify = jwt::verify<jwt::traits::open_source_parsers_jsoncpp>()
							.allow_algorithm(jwt::algorithm::none{})
							.with_claim("test", array_claim);
	ASSERT_NO_THROW(verify.verify(decoded_token));
}

TEST(OspJsoncppTest, VerifyObject) {
	jwt::traits::open_source_parsers_jsoncpp::string_type token =
		"eyJhbGciOiJIUzI1NiJ9.eyJuYW1lc3BhY2UiOnsiYXBpLXgiOlsxXX19.F8I6I2RcSF98bKa0IpIz09fRZtHr1CWnWKx2za-tFQA";
	const auto decoded_token = jwt::decode<jwt::traits::open_source_parsers_jsoncpp>(token);

	jwt::basic_claim<jwt::traits::open_source_parsers_jsoncpp> object_claim;
	std::istringstream iss{"{\"api-x\": [1]}"};
	iss >> object_claim;
	const auto verify = jwt::verify<jwt::traits::open_source_parsers_jsoncpp>()
							.allow_algorithm(jwt::algorithm::hs256("test"))
							.with_claim("namespace", object_claim);
	ASSERT_NO_THROW(verify.verify(decoded_token));
}
