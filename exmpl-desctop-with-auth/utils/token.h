#pragma once

#include "Config.h"

#include <cpr/cpr.h>
#include <jwt-cpp/jwt.h>


namespace token{

class TokenManager: public cfg::Config {

    private:
        bool UpdateAccessToken();
    
    protected:
        virtual void sendRegistrationRequest(std::string username, std::string password){};
        virtual void sendLoginRequest(std::string username, std::string password){};


    public:
        TokenManager(){};
        bool ValidateToken();
        

};

}