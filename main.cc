#include <drogon/drogon.h>
#include "ServisConfig.h"
#include <iostream>

#include <cstdlib>



int main(int argc, char* argv[]) {
    

    if(argc > 3){
        return 1;
    }


    std::string serverCfgPath = argv[1];


    std::string servisCfgPath = argv[2];
    try
    {
        setenv("AUTH_SERVIS_DB_DIR", servisCfgPath.c_str(), 1);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    

    drogon::app()
        .loadConfigFile(serverCfgPath)
        .run();
    
        
    return 0;
}
