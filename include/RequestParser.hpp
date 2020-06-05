//#include "RequestParser.hpp"
#pragma once
#include <string>
#include <iostream>
#include "json.hpp"
#include "HttpObject.hpp"

typedef nlohmann::json  json;

class RequestParser 
{

    private:
        std::string buffer;
    public: 
        
        void ParseHttpHeader (HttpObject& http)
        {
            
        }
        json ParseStringtoJSON (const std::string& str)
        {
            return json::parse(str);
        }
        
};