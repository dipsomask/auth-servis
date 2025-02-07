#pragma once

#include <pqxx/pqxx>
#include <drogon/drogon.h>
#include <jwt-cpp/jwt.h>
#include "configDb.h"


namespace authAndValid{

void ValidateKey(const std::string &username, const std::string &key);

std::string GenerateJwt(const std::string &username);

std::string generateAndCommitAccessToken(const std::string &username);

std::string generateAndCommitRefreshToken(const std::string &username);

}