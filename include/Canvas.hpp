#pragma once 
#include <iostream>
#include <string> 
#include "RequestHandler.hpp"
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
        Canvas (const std::string& _token)
        {
            SetToken (_token);
        }
        Canvas (const std::string& _url)
        {
            SetUrl (_url);
        }
        Canvas (const std::string& _token, const std::string& _url)
        {
            SetToken(_token);
            SetUrl (_url);
        }
    //set authentication token 
        void SetToken (const std::string& _token)
        {
            token = _token;
        }
    //set url
        void SetUrl (const std::string& _url)
        {
            base_url = _url;
        }
    //member functions 
        PageList GetPagesList (const std::string& _url)
        {
            
        }
        Page GetPage (const std::string& _url)
        {
            
        }

};