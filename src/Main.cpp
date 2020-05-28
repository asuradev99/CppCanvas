#include <list>
#include <fstream>
#include <iostream>
#include <string.h>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

using namespace std;

int main(){

    //obtain key from first line of file key.txt
    fstream keyHandle;
    string key;
    keyHandle.open("Key");
    keyHandle >> key;
    
    //cleanup and request 
    curlpp::Cleanup clean;
    curlpp::Easy req;
    
    //target url initialization 
    curlpp::options::Url url(string("https://graniteschools.instructure.com/api/v1/courses/1337964/pages"));
    
    //authentication 
    string authHeader = "Authorization: Bearer ";
    authHeader.append(key);
    list<string> headers {authHeader};
    curlpp::options::HttpHeader hdr(headers);

    //set options and perform request
    req.setOpt(url);
    req.setOpt(hdr);
    req.perform();
}