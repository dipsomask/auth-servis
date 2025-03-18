#include "Config.h"
#include "token.h"

#include <cpr/cpr.h>
#include <jwt-cpp/jwt.h>


bool token::TokenManager::UpdateAccessToken(){

    try
    {
        std::string refresh_t = getKeyOnValue("refresh-t");

        jwt::decoded_jwt decoded = jwt::decode(refresh_t);
        std::string username = decoded.get_subject();


        cpr::Response resp = cpr::Post(
            cpr::Url{"http://localhost:3000/updateaccesst"},
            cpr::Header{{"refresh-token", refresh_t}, {"username", username}}
        );

        int statusCode = resp.status_code;
        
        if(statusCode != 200){
            std::cout << "TokenManager message: \n" << "   " << 
                        "auth-servis send response status code " << 
                        std::to_string(statusCode) << "." <<
                        std::endl;
            
            return false;
        }

        std::cout << "TokenManager message: \n" << "    " <<
                    "auth-servis send 200 request status code with: \n" <<
                    "        message: " << resp.text << std::endl <<
                    "        headers: " << resp.raw_header << std::endl;
        
        auto access_t_HeaderValue = resp.header["access-token"];
        if(access_t_HeaderValue.empty()){
            std::cout << "TokenManager message: \n" << "    " <<
                        "auth-servis send 200 request status code\n" <<
                        "BUT don't send 'access-token' header." << std::endl;
            
            return false;
        }

        int updatingConfing = updateAllDataInConfigWithJson(
                                "access-t", 
                                access_t_HeaderValue
                            );
        if(updatingConfing != 0)
            return false;

        return true;
    }
    catch(const std::exception& e)
    {
        std::cout << "Invalid refresh-token." << '\n';
        return false;
    }
    

}

bool token::TokenManager::ValidateToken()
{

    try
    {

        std::string access_t = getKeyOnValue("access-t");
        std::string secret = getKeyOnValue("secret");

        auto verifier = jwt::verify()
            .with_issuer("auth_servis")
            .allow_algorithm(jwt::algorithm::hs256{secret});

        jwt::decoded_jwt decoded = jwt::decode(access_t);

        verifier.verify(decoded);
    }
    catch(const std::exception& e)
    {
        std::cout << "TokenManager error: \n" << "   " << e.what() << std::endl;
        bool tokenUpdated = UpdateAccessToken();
        if (!tokenUpdated)
            return false;
        else
            return true;
    }
    
    return true;
}
