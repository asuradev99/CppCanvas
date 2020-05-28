#include "RequestHandler.hpp"
#include <fstream>
int main () 
{
    //compiles with g++ testusage.cpp -L. -lrequesthandler -lcurl -lcurlpp -o a.out
    //obtain key from first line of file key.txt
    std::fstream keyHandle;
    std::string key;
    keyHandle.open("key.txt");
    keyHandle >> key;
    std::cout << key << std::endl;
    RequestHandler requests("https://graniteschools.instructure.com/api/v1/",key); 
    std::cout << requests.GetRequest("courses/1337964/pages");
}
