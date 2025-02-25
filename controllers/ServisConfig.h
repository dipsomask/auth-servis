#pragma once

#include <string>
#include <jsoncpp/json/json.h>


namespace configdb {


    class ServisConfig {
        private:
            std::string configPath;
            std::string dbhost;
            std::string dbname;
            std::string dbuser;
            std::string dbpasswd;
            int dbport;

            std::string secret;
        
        public:
            ServisConfig(){};
            ServisConfig(const std::string& configPath);      

            std::string getConnectionArgs();
            std::string getSecretKey();
    };


}
