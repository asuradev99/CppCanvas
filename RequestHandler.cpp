#include <iostream>
#include <string>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

class RequestHandler {
    const std::string token;
    const std::string base_url; 

    curlpp::Cleanup cleanup;
    curlpp::Easy handler;
    RequestHandler (const std::string& _base_url, const std::string& _token) : 
        base_url(_base_url), token (_token)
    {
        //initalize request handler
    }

    void Get () 
    {
        //get the specified url and return a JSON response
    }
    //remember to reset the handle after every function


    
};
int main () 
{
    return 0;
}