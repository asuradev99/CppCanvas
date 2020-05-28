
#include <iostream>
#include <string.h>
#include <list>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

class RequestHandler {
    private: 
        std::string token;
        std::string base_url;
        curlpp::Cleanup cleanup;
        curlpp::Easy handler;
    public: 
        RequestHandler (const std::string& _base_url, const std::string& _token);
        std::string GetRequest(const std::string& url);

};