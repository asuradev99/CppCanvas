#include "Canvas.hpp"
int main (int argc, char* argv[]) 
{
    std::cout << argc << '\n';
    std::string key = argv[1];
    std::string url = "https://graniteschools.instructure.com/api/v1/";
    Canvas canvas (key,url);
    Page page = canvas.GetPage(std::string ("courses/1337964/pages/aug-26-slash-27"));
}
