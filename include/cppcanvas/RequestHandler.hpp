#pragma once
#include <iostream>
#include <string>
#include <list>
#include "HttpObject.hpp"
#include "Session.hpp"
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <sstream>

namespace CppCanvas {
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
    struct PostOptions {
        std::string url, opt;
        bool include_hdr;
        bool include_body;
        bool PUT = false;
        PostOptions (const std::string& _url, const std::vector<std::string> _params, const bool& hdr, const bool& body) :
        url (_url), include_hdr(hdr), include_body(body) 
        {
            for (auto x : _params)
            {
                opt += (x + "&");
            }
        }
    };
    class RequestHandler {
        private: 
            std::string token;
            std::string responsebuffer;
            std::string base_url;
            cURLpp::Cleanup cleanup;
            cURLpp::Easy handler;
        public: 
            RequestHandler (const Session & session) : 
                base_url(session.url), token (session.token) {}
            void SetUrl (const std::string& url)
            {
                std::string full_url = base_url.append(url);
                std::cout << full_url << "\n";
                handler.setOpt(new cURLpp::Options::Url (full_url));
            }
            void IncludeContent(const bool& include_header, const bool& include_body)
            {
                handler.setOpt(new cURLpp::Options::Header(int(include_header)));
                handler.setOpt(new cURLpp::Options::NoBody(int(!include_body)));
            }
            CppCanvas::HttpObject GetRequest (const RequestOptions& options)
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

                CppCanvas::HttpObject output (httpresponse.str());
                return output;
            }  
            void PostRequest (const PostOptions& options)
            {
                std::string auth_header = "Authorization: Bearer ";
                auth_header.append(token);
                std::list<std::string> headers {auth_header};
              //  headers.push_back("Content-Type: application/json");

                SetUrl (options.url);
                IncludeContent(options.include_hdr,options.include_body);
                handler.setOpt(new curlpp::options::HttpHeader(headers)); 
                handler.setOpt(new curlpp::options::CustomRequest("PUT"));
                std::cout << options.opt << "\n";

                handler.perform();
                handler.reset();
            }

    };
}

