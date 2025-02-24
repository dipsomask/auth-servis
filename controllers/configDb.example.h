#ifndef CONFIG_DB_H
#define CONFIG_DB_H

#include <string>

namespace configdb {
        
    inline const std::string name = "not_found";
    inline const std::string rdbms = "postgresql";
    inline const std::string host = "127.0.0.1";
    inline const int port = 5432;
    inline const std::string dbname = "testdrogonauth";
    inline const std::string user = "postgres";
    inline const std::string passwd = "password";

    inline const std::string secret = 
        "dflgkjhlvjclxcjvoiy78962yr2m73mr2,.c03eri9i,98U807tn87tymNYIUOJSDLKFSMDFG";

    inline const std::string connArgs = "host=" + host +
                                        " port=" + std::to_string(port) +
                                        " dbname=" + dbname +
                                        " user=" + user +
                                        " password=" + passwd;
}

#endif // CONFIG_DB_H
