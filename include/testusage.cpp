#include "Canvas.hpp"
//compiles with g++ testusage.cpp -lcurl -lcurlpp
int main (int argc, char* argv[]) 
{
 
    std::string key = argv[1];
    std::string url = "https://canvas.instructure.com/api/v1/";
    Canvas canvas (key,url);
    Page page = canvas.GetPage(std::string ("courses/2120073/pages/sample-page"));

}
//test commit