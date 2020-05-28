#include "RequestHandler.hpp"
#include <sstream>
//compiler flags: -lcurl -lcurlpp -c RequestHandler.cpp
RequestHandler::RequestHandler (const std::string& _base_url, const std::string& _token) : 
        base_url(_base_url), token (_token)
    {
        //initalize request handler
    }

std::string RequestHandler::GetRequest(const std::string& url) 
    {
        std::stringstream httpresponse; 
        std::string full_url = base_url.append(url);
        std::string auth_header = "Authorization: Bearer ";
        auth_header.append(token);
        std::cout << auth_header << std::endl;
        std::list<std::string> headers {auth_header};

        handler.setOpt(new curlpp::options::Verbose(true));
        handler.setOpt(new cURLpp::Options::Url (full_url));
        handler.setOpt(new cURLpp::Options::HttpHeader (headers));
        handler.setOpt(new cURLpp::Options::WriteStream (&httpresponse));
        handler.perform();
        handler.reset();

        return httpresponse.str();
        //get the specified url and return a JSON response
    }
//remember to reset the handle after every function
    
