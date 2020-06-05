#include "RequestHandler.hpp"
#include "RequestParser.hpp"
#include "HttpObject.hpp"
#include <fstream>
int main () 
{
    //compiles with g++ testusage.cpp -L. -lrequesthandler -lcurl -lcurlpp -o a.out
    //obtain key from first line of file key.txt
    std::fstream keyHandle;
    std::string key;
    HttpObject response;
    RequestParser parser;
    keyHandle.open("key.txt");
    keyHandle >> key;
    std::cout << key << std::endl;
    RequestHandler requests("https://graniteschools.instructure.com/api/v1/",key); 
    response = requests.GetRequest("courses/1337964/pages");
    response.SeparateContents();
    std::vector<std::string> result = response.ParseHttpHeader(response.GetRawHeader());
}
