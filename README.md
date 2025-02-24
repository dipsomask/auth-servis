# Simple registration/authorization servis on Drogon + jwt-cpp

# needed packeges:
- libssl-dev, libpqxx-dev
- drogon abd jwt-cpp (you can see installation guide in https://github.com/drogonframework/drogon.git anb https://github.com/Thalhammer/jwt-cpp.git) 

# config.json:
- Rename and change config.example.ssl.json or config.example.nossl.json to config.json
- Or you can use your different configuration

# configDB.h:
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
- **Change it with your db setting**
