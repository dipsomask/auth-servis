#include "ServisConfig.h"
#include <string>
#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>
#include <cstdlib>




configdb::ServisConfig::ServisConfig(const std::string& path){

    Json::Value data;
    
    std::ifstream file(
        path,
        std::ifstream::binary);
    if(!file.is_open()){

        throw std::runtime_error("Can't open the file");
    }

    file >> data;

    file.close();
    
    if(data.empty()){
        throw std::runtime_error("File is empty");
    }

    configPath = path;
    dbhost = data["dbhost"].asString();
    dbname = data["dbname"].asString();
    dbuser = data["dbuser"].asString();
    dbpasswd = data["dbpasswd"].asString();
    dbport = data["dbport"].asInt();

    secret = data["secret"].asString();

}

std::string configdb::ServisConfig::getConnectionArgs(){

    return "host=" + dbhost +
           " port=" + std::to_string(dbport) +
           " dbname=" + dbname +
           " user=" + dbuser +
           " password=" + dbpasswd;

}

std::string configdb::ServisConfig::getSecretKey(){

    return secret;

}

