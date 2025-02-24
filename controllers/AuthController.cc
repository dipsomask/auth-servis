#include "AuthController.h"
#include "configDb.h"

#include <drogon/drogon.h>
#include <jsoncpp/json/json.h>
#include <pqxx/pqxx>


void AuthController::registration(const drogon::HttpRequestPtr &req,
        std::function<void(const drogon::HttpResponsePtr &)> &&callback){

    auto headers = (*req).getHeaders();

    if(headers.empty() || headers.find("username") == headers.end() || 
        headers.find("passwd") == headers.end() || 
        headers["username"].empty() || headers["passwd"].empty()){
        
        Json::Value err;
        err["status"] = "error";
        err["message"] = "Invalid headers";

        auto response = drogon::HttpResponse::newHttpJsonResponse(err);
        response->setStatusCode(drogon::HttpStatusCode::k400BadRequest);
        
        callback(response);
        return;

    }

    std::string username = headers["username"];
    std::string passwd = headers["passwd"];

    try{

        pqxx::connection conn(configdb::connArgs);
        pqxx::work txn(conn);

        auto result = txn.exec(
            "INSERT INTO users (username, password_hash) VALUES (" + 
            txn.quote(username) + ", " +
            txn.quote(drogon::utils::getSha256(passwd)) + ")"
        );
        if (!result.empty()) {
            throw std::runtime_error("Unexpected result from INSERT query");
        }
        txn.commit();

        Json::Value resp;
        resp["status"] = "success";
        resp["message"] = "User registred successfully";

        auto response = drogon::HttpResponse::newHttpJsonResponse(resp);
        response->setStatusCode(drogon::HttpStatusCode::k200OK);
        
        callback(response);

    }
    catch(const std::exception& e){
        
        Json::Value err;
        err["status"] = "error";
        err["error"] = e.what();

        auto response = drogon::HttpResponse::newHttpJsonResponse(err);
        response->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);
        
        callback(response);

    }
    
}


#include "auth.h"
using namespace authAndValid;

void AuthController::login(const drogon::HttpRequestPtr &req,
        std::function<void(const drogon::HttpResponsePtr &)> &&callback){
    
    auto headers = (*req).getHeaders();
        
    if(headers.empty() || headers.find("username") == headers.end() || 
    headers.find("passwd") == headers.end() || 
    headers["username"].empty() || headers["passwd"].empty()){
        
        Json::Value err;
        err["status"] = "error";
        err["message"] = "Invalid username or password";

        auto response = drogon::HttpResponse::newHttpJsonResponse(err);
        response->setStatusCode(drogon::HttpStatusCode::k400BadRequest);
        
        callback(response);
        return;

    }

    std::string username = headers["username"];
    std::string passwd = headers["passwd"];

    try{

        pqxx::connection conn(configdb::connArgs);
        pqxx::work txn(conn);

        auto result = txn.exec(
            "SELECT * FROM users WHERE username = " + 
            txn.quote(username) + " AND password_hash = " +
            txn.quote(drogon::utils::getSha256(passwd)) + ";"
        );
        if (result.empty()) {
            throw std::runtime_error("Unexpected result from Select query");
        }
        txn.commit();

        std::string refreshToken = authAndValid::generateAndCommitRefreshToken(username);
        std::string accessToken = authAndValid::generateAndCommitAccessToken(username);

        Json::Value resp;
        resp["status"] = "success";
        resp["message"] = "User successfully logined";

        auto response = drogon::HttpResponse::newHttpJsonResponse(resp);
        response->setStatusCode(drogon::HttpStatusCode::k200OK);
        response->addHeader("refresh-token", refreshToken);
        response->addHeader("access-token", accessToken);

        callback(response);

    }
    catch(const std::exception& e){
        
        Json::Value err;
        err["status"] = "error";
        err["message"] = e.what();

        auto response = drogon::HttpResponse::newHttpJsonResponse(err);
        response->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);
        
        callback(response);

    }
    

}

void AuthController::updateAccessToken(const drogon::HttpRequestPtr &req,
        std::function<void(const drogon::HttpResponsePtr &)> &&callback){
    
    auto headers = (*req).getHeaders();

    if (headers.empty() || headers.find("refresh-token") == headers.end() || 
    headers.find("username") == headers.end() || 
    headers["refresh-token"].empty() || headers["username"].empty()){
        Json::Value err;
        err["status"] = "error";
        err["message"] = "Invalid parms";

        auto response = drogon::HttpResponse::newHttpJsonResponse(err);
        response->setStatusCode(drogon::HttpStatusCode::k400BadRequest);
        
        callback(response);
        return;
    }

    std::string refreshToken = headers["refresh-token"];
    std::string username = headers["username"];

    try
    {

        pqxx::connection conn(configdb::connArgs);
        pqxx::work txn(conn);

        auto result = txn.exec(
            "SELECT * FROM users WHERE username = " + txn.quote(username) +
            " AND refresh_token = " + txn.quote(refreshToken) + ";"
        );
        if(result.empty()){
            Json::Value err;
            err["status"] = "error";
            err["message"] = "Invalid or expired refresh token";

            txn.commit();

            auto response = drogon::HttpResponse::newHttpJsonResponse(err);
            response->setStatusCode(drogon::HttpStatusCode::k401Unauthorized); 
            
            callback(response);
            return;
        }
        txn.commit();

        authAndValid::validateRefreshToken(refreshToken);

        std::string token = authAndValid::generateAndCommitAccessToken(username);

        Json::Value resp;
        resp["status"] = "success";
        resp["message"] = "Token update successfuly";

        auto response = drogon::HttpResponse::newHttpJsonResponse(resp);
        response->addHeader("access-token", token);
        callback(response);

    }
    catch(const std::exception& e)
    {
        Json::Value err;
        err["status"] = "error";
        err["message"] = e.what();

        auto response = drogon::HttpResponse::newHttpJsonResponse(err);
        response->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);

        if(std::string(e.what()) == "Expired token lifetime"){

            response->setStatusCode(drogon::HttpStatusCode::k401Unauthorized);
        }
        
        callback(response);
    }

}

