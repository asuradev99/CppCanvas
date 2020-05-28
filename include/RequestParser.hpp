//#include "RequestParser.hpp"
#pragma once
#include <string>
#include <iostream>
#include "json.hpp"

typedef nlohmann::json  json;
class RequestParser 
{
    private:
        std::string buffer;
    public: 
        json ParseStringtoJSON (const std::string& str)
        {
            return json::parse(str);
        }
        
};