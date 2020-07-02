#pragma once
#include <iostream>
#include <string>
#include "RequestHandler.hpp"
#include "HttpObject.hpp"
#include "PageList.hpp"
#include "Page.hpp"
#include "Session.hpp"
namespace CppCanvas {
    /**
     * @brief this is a test comment
     * 
     */
    class Canvas
    {
        private:
            std::string token;
            std::string base_url;
            CppCanvas::Session session {"", ""};

        public:
        //overloaded constructors
            /**
             * @brief Construct a new Canvas object which takes in the API token and the base URL in the form of std::strings
             * 
             * @param _token 
             * @param _url 
             */
            Canvas (std::string _token, std::string _url) :
            token(_token), base_url(_url) {
                session.token = token;
                session.url = base_url;
            }
            /**
            * @brief Returns a CppCanvas::Page object with parameters from the canvas page at the specified URL
            * 
            * @param _url
            * 
            */
            CppCanvas::Page GetPage (const std::string& _url)
            {
                CppCanvas::RequestHandler requests (session);
                CppCanvas::RequestOptions options (_url, true, true);
                CppCanvas::HttpObject response = requests.GetRequest(options);
                CppCanvas::Page response_page (response, session);
                return response_page;
            }


    };

}
