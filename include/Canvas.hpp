#pragma once
#include <iostream>
#include <string>
#include "RequestHandler.hpp"
#include "HttpObject.hpp"
#include "PageList.hpp"
#include "Page.hpp"

class Canvas
{

    private:
        std::string token;
        std::string base_url;
        
    public:
    //overloaded constructors
        Canvas () {}
        Canvas (const std::string& _token, const std::string& _url) :
        token(_token), base_url(_url)
        {

        }
    //member functions
        PageList GetPagesList (const std::string& _url)
        {

        }
        Page GetPage (const std::string& _url)
        {
            RequestHandler requests (base_url, token);
            RequestOptions options (_url, true, true);
            HttpObject response = requests.GetRequest(options);
            Page response_page (response);
            return response_page;
        }
        

};
