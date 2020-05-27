#include <iostream>
#include <string>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

class RequestHandler {
    const std::string token;
    const std::string url; 

    RequestHandler (const std::string& _url, const std::string& _token) : 
        url(_url), token (_token)
    {
        //initalize request handler
    }

    void Get () 
    {
        //get the specified url and return a JSON response
    }

    

    
};
int main () 
{
    return 0;
}