#include "../include/cppcanvas/Canvas.hpp"
/*
    This example gets a canvas page and 
    edits it. 
*/
int main (int argc, char* argv[]) 
{
    //Check if the user has specified their api token as a flag
    if (argc < 2) {
        std::cerr << "Please specify Api token";
        return 1;
    }
    //get api token as a string from flag and init the api url 
    std::string key = argv[1];
    std::string url = "https://canvas.instructure.com/api/v1/";

    //start a canvas session which is capable of sending GET and POST requests through the API
    CppCanvas::Canvas canvas (key, url);

    //Get a page from the specified url 
    CppCanvas::Page page = canvas.GetPage("courses/2120073/pages/sample-page");

    //get a json attribute specific to the page
    std::cout << page.get(CppCanvas::Attributes::Page::title) << "\n";
    page.Edit();
    
}
