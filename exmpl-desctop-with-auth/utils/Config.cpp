#include "Config.h"

#include <string>
#include <iostream>
#include <fstream>
#include <jwt-cpp/jwt.h>
#include <nlohmann/json.hpp>
#include <cstdlib>

using json = nlohmann::json;

cfg::Config::Config(){

    try
    {
        std::ifstream file(getenv("CONFIG_EXMPL_DESKTOP_WITH_AUTH"));
        if(!file.is_open()){
            throw std::runtime_error(
                "File opening error:\n    can't open file\n    " + 
                std::string(getenv("CONFIG_EXMPL_DESKTOP_WITH_AUTH"))
            );
        }

        json data = json::parse(file);

        if(file.is_open())
          file.close();
        if(data.empty())
          throw std::runtime_error("File is empty");

        configData = data;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    

}

std::string cfg::Config::getKeyOnValue(std::string key){

    try
    {
        if(!configData.contains(key))
            throw std::runtime_error(
                "SYSTEM ERROR:\n    Has no one value named " + key
            );
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    
    return configData[key];

}

int cfg::Config::updateAllDataInConfigWithJson(std::string key, std::string value){
    
    try
    {
        std::ofstream file(getenv("CONFIG_EXMPL_DESKTOP_WITH_AUTH"));
        
        configData[key] = value;

        if(!file.is_open()){
            throw std::runtime_error(
                "File opening error:\n    can't open file\n    " +
                std::string(getenv("CONFIG_EXMPL_DESKTOP_WITH_AUTH"))
            );
        }

        file << configData.dump(4);
        if(file.is_open())
            file.close();
        
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
        return 1;
    }
    
    return 0;
}
