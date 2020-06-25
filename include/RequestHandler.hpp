#pragma once
#include <iostream>
#include <string>
#include <list>
#include "HttpObject.hpp"
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <sstream>

struct RequestOptions {
    std::string url; 
    bool include_hdr;
    bool include_body; 
    RequestOptions (const std::string& _url, const bool& hdr, const bool& body) :
    url(_url), include_hdr(hdr), include_body(body) 
    {
        
    }
    RequestOptions () {}
};
class RequestHandler {
    private: 
        std::string token;
        std::string responsebuffer;
        std::string base_url;
        cURLpp::Cleanup cleanup;
        cURLpp::Easy handler;
    public: 
        RequestHandler (const std::string& _base_url, const std::string& _token) : 
        base_url(_base_url), token (_token)
        {
        }
        void SetUrl (const std::string& url)
        {
            std::string full_url = base_url.append(url);
            handler.setOpt(new cURLpp::Options::Url (full_url));
        }
        void IncludeContent(const bool& include_header, const bool& include_body)
        {
            handler.setOpt(new cURLpp::Options::Header(int(include_header)));
            handler.setOpt(new cURLpp::Options::NoBody(int(!include_body)));
        }
        HttpObject GetRequest (const RequestOptions& options)
        {
            std::stringstream httpresponse; 
            std::string auth_header = "Authorization: Bearer ";
            auth_header.append(token);
            std::list<std::string> headers {auth_header};
            
            SetUrl(options.url);
            IncludeContent(options.include_hdr,options.include_body);

            handler.setOpt(new cURLpp::Options::HttpHeader (headers));
            handler.setOpt(new cURLpp::Options::WriteStream (&httpresponse));

            handler.perform();
            handler.reset();

            HttpObject output (httpresponse.str());
            return output;
        }  
        HttpObject PostRequest () {
            
        }

};
