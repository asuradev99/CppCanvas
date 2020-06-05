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
        void GetPage (const std::string& _url)
        {
            RequestHandler requests (base_url, token);
            HttpObject response = requests.GetRequest(_url, true, true);
            
            
        }
        
};