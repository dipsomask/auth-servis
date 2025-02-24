#pragma once

#include <drogon/HttpController.h>



class AuthController : public drogon::HttpController<AuthController> {

public:
    METHOD_LIST_BEGIN

    ADD_METHOD_TO(
        AuthController::registration,
        "/registration",
        drogon::Post
    );

    ADD_METHOD_TO(
        AuthController::login,
        "/login",
        drogon::Get
    );
    
    ADD_METHOD_TO(
        AuthController::updateAccessToken,
        "/updateaccesst",
        drogon::Post
    );
    
    METHOD_LIST_END


    void registration(const drogon::HttpRequestPtr &req,
        std::function<void(const drogon::HttpResponsePtr &)> &&callback);

    void login(const drogon::HttpRequestPtr &req,
        std::function<void(const drogon::HttpResponsePtr &)> &&callback);

    void updateAccessToken(const drogon::HttpRequestPtr &req,
        std::function<void(const drogon::HttpResponsePtr &)> &&callback);

};