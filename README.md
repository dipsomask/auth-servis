# Simple registration/authorization servis (no ssl) on Drogon + jwt-cpp (and other)

# needed packeges (if don't user docker compose):
- libc6, gcc, g++, cmake, pkg-config, libpqxx-dev, libjsoncpp-dev, uuid-dev, zlib1g-dev, openssl, libssl-dev, libmariadb3, libyaml-cpp0.8, postgresql-all
- drogon, postgresql
(you can see installation guide in
https://github.com/drogonframework/drogon.git)

_____________________________________________________
# Make enviromental using deb packege and your database:
- Install (.deb) packege with servise.
- You should create database in postgres.
- Then make table, making this sql request:
    - put this code to create needed table in your database:
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
- Make two files in any directory or clone Examples (change their with your configuration):
```
config file for drogon settings (config.example.nossl.json - example)
servis config file (servisCfg.example.json - example) (include database connecting configiration)
```
______________________________________________________
- Run this command to start server.
```
/usr/bin/test-db-servis /absolute/path/to/config/file/for/drogon/settings /absolute/path/to/servis/config/file
```
_____________________________________________________
# Make enviromental using docker compose:
- Install docker with docker compose
- Download 2 files from "https://github.com/drogonframework/drogon.git" repository to any directory:
    - docker-compose.yml;
    - init.sql.
- Run this command from directory with downloaded files:
```
docker compose up --build
```
- In server container you can change config files for database and server settings, if you want (NOT RECOMENDED).
Also you can see server and database setting in /usr/src/ config files in server container.

