#include "AuthController.h"
#include "configDb.h"

#include <drogon/drogon.h>
#include <jsoncpp/json/json.h>
#include <pqxx/pqxx>


void AuthController::registration(const drogon::HttpRequestPtr &req,
        std::function<void(const drogon::HttpResponsePtr &)> &&callback,
        const std::string &username,
        const std::string &passwd){

    if(username.empty() || passwd.empty()){
        
        Json::Value err;
        err["error"] = "Invalid parms";

        auto response = drogon::HttpResponse::newHttpJsonResponse(err);
        response->setStatusCode(drogon::HttpStatusCode::k400BadRequest);
        
        callback(response);
        return;

    }

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
        resp["message"] = "User registred successfully";

        auto response = drogon::HttpResponse::newHttpJsonResponse(resp);
        response->setStatusCode(drogon::HttpStatusCode::k200OK);
        
        callback(response);

    }
    catch(const std::exception& e){
        
        Json::Value err;
        err["error"] = e.what();

        auto response = drogon::HttpResponse::newHttpJsonResponse(err);
        response->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);
        
        callback(response);

    }
    
}


#include "auth.h"
using namespace authAndValid;

void AuthController::login(const drogon::HttpRequestPtr &req,
        std::function<void(const drogon::HttpResponsePtr &)> &&callback,
        const std::string &username,
        const std::string &passwd){
    
    if(username.empty() || passwd.empty()){
        
        Json::Value err;
        err["error"] = "Invalid parms";

        auto response = drogon::HttpResponse::newHttpJsonResponse(err);
        response->setStatusCode(drogon::HttpStatusCode::k400BadRequest);
        
        callback(response);
        return;

    }

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
        std::string jwt = authAndValid::GenerateJwt(username);

        Json::Value resp;
        resp["message"] = "User successfully logined";
        resp["jwt"] = jwt;
        resp["refresh-token"] = refreshToken;
        resp["access-token"] = accessToken;

        auto response = drogon::HttpResponse::newHttpJsonResponse(resp);
        response->setStatusCode(drogon::HttpStatusCode::k200OK);
        
        callback(response);

    }
    catch(const std::exception& e){
        
        Json::Value err;
        err["error"] = e.what();

        auto response = drogon::HttpResponse::newHttpJsonResponse(err);
        response->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);
        
        callback(response);

    }
    

}
