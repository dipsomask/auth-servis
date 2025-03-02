# Simple registration/authorization servis on Drogon + jwt-cpp (and other)

# needed packeges:
- libc6, gcc, g++, cmake, pkg-config, libpqxx-dev, libjsoncpp-dev, uuid-dev, zlib1g-dev, openssl, libssl-dev, libmariadb3, libyaml-cpp0.8, postgresql-all
- drogon, postgresql
(you can see installation guide in
https://github.com/drogonframework/drogon.git) 

_____________________________________________________
# how to use:
- install (.deb) packege with servise
- you should create database in postgres
- then make table, making this sql request:
- Put this code to create needed table in your database:
```
CREATE TABLE users(
username varchar(100) NOT NULL,
    password_hash varchar(255) NOT NULL,
    access_token varchar(250),
    refresh_token varchar(250),
    PRIMARY KEY(username)
);
CREATE UNIQUE INDEX users_username_key ON users USING btree ("username");
```

______________________________________________________
- make two files in any directory or clone Examples (change their with your configuration):
```
config file for drogon settings (config.example.nossl.json - example)
servis config file (servisCfg.example.json - example) (include database connecting configiration)
```
______________________________________________________
- run this command to start servr
```
/usr/bin/test-db-servis /absolute/path/to/config/file/for/drogon/settings /absolute/path/to/servis/config/file
```

