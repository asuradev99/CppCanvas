//#include "RequestParser.hpp"
#pragma once
#include <string>
#include <iostream>
#include "json.hpp"
#include "HttpObject.hpp"
#include <httpparser/response.h>
#include "httpparser/httpresponseparser.h"
typedef nlohmann::json  json;

class RequestParser 
{

    private:
        std::string buffer;
    public: 
        
        void ParseHttpHeader (HttpObject& input)
        {
            input_rawheader = 
            httpparser::Response response;
            httpparser::HttpResponseParser parser;
            httpparser::HttpResponseParser::ParseResult result = parser.parse(response, input, input + strlen(input));
            std::cout << response.inspect() << std::endl;
        }
        json ParseStringtoJSON (const std::string& str)
        {
            return json::parse(str);
        }
        
};