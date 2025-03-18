#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <jwt-cpp/jwt.h>
#include <nlohmann/json.hpp>
#include <cstdlib>

namespace cfg{

    class Config{

        private:
            nlohmann::json configData;

        public:
            Config();
            std::string getKeyOnValue(std::string key);
            int updateAllDataInConfigWithJson(std::string key, std::string value);
    };

}
