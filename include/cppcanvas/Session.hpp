#pragma once
#include <string>
namespace CppCanvas 
{
    struct Session {
        std::string token, url;
        Session (std::string _token, std::string _url) 
        : token (_token), url (_url)
        {
            
        }
    };
}



