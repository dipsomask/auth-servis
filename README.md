# Simple registration/authorization servis on Drogon + jwt-cpp

# config.json:
- Change config.json to config.example.ssl.json for using ssl, but you should add ssl keys to your system.
- Change config.json to config.example.nossl.json for using it without ssl.
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
