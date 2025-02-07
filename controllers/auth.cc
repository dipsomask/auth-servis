#include "auth.h"

void authAndValid::ValidateKey(const std::string &username, const std::string &key){
    
    if(username.empty() || key.empty()){
        throw std::domain_error("Check failed");
    }

    pqxx::connection conn(configdb::connArgs);
    pqxx::work txn(conn);

    auto result = txn.exec(
        "SELECT * FROM users WHERE username = " + txn.quote(username) + " AND " +
        "api_key = " + txn.quote(key) + ";"
    );
    if(result.empty()){
        throw std::domain_error("Check failed");
    }

}

std::string authAndValid::GenerateJwt(const std::string &username){

    if(username.empty()){
        throw std::domain_error("User not found");
    }

    std::string token = jwt::create()
        .set_issuer("auth_servis")
        .set_subject(username)
        .set_type("JWS")
        .set_payload_claim(
            "username", jwt::claim(username)
        )
        .set_expires_at(
            std::chrono::system_clock::now() +
            std::chrono::minutes(30)
        )
        .sign(
            jwt::algorithm::hs256{configdb::secret}
        );

    if(token.empty()){
        throw std::domain_error("Bad generation");
    }

    return token;
}


std::string authAndValid::generateAndCommitAccessToken(const std::string &username){
    
    if(username.empty()){
        throw std::domain_error("User not found");
    }

    std::string token = drogon::utils::getUuid();

    pqxx::connection conn(configdb::connArgs);
    pqxx::work txn(conn);

    auto result = txn.exec(
        "UPDATE users SET access_token = " + txn.quote(token) +
        " WHERE username = " + txn.quote(username) + ";"
    );
    if (!result.empty()) {
        throw std::runtime_error("Unexpected result from Update query");
    }
    txn.commit();

    return token;

}

std::string authAndValid::generateAndCommitRefreshToken(const std::string &username){
    
    if(username.empty()){
        throw std::domain_error("User not found");
    }

    std::string token = drogon::utils::getUuid();

    pqxx::connection conn(configdb::connArgs);
    pqxx::work txn(conn);

    auto result = txn.exec(
        "UPDATE users SET refresh_token = " + txn.quote(token) +
        " WHERE username = " + txn.quote(username) + ";"
    );
    if (!result.empty()) {
        throw std::runtime_error("Unexpected result from Update query");
    }
    txn.commit();

    return token;

}