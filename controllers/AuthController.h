#pragma once

#include <drogon/HttpController.h>



class AuthController : public drogon::HttpController<AuthController> {

public:
    METHOD_LIST_BEGIN

    ADD_METHOD_TO(
        AuthController::registration,
        "/registration?username={1}&passwd={2}",
        drogon::Post
    );

    ADD_METHOD_TO(
        AuthController::login,
        "/login?username={1}&passwd={2}",
        drogon::Get
    );
    
    ADD_METHOD_TO(
        AuthController::updateAccessToken,
        "/updateaccesst?refreshToken={1}&username={2}",
        drogon::Post
    );
    
    METHOD_LIST_END


    void registration(const drogon::HttpRequestPtr &req,
        std::function<void(const drogon::HttpResponsePtr &)> &&callback,
        const std::string &username,
        const std::string &passwd);

    void login(const drogon::HttpRequestPtr &req,
        std::function<void(const drogon::HttpResponsePtr &)> &&callback,
        const std::string &username,
        const std::string &passwd);

    void updateAccessToken(const drogon::HttpRequestPtr &req,
        std::function<void(const drogon::HttpResponsePtr &)> &&callback,
        const std::string &refreshToken,
        const std::string &username);

};