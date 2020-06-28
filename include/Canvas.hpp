#pragma once
#include <iostream>
#include <string>
#include "RequestHandler.hpp"
#include "HttpObject.hpp"
#include "PageList.hpp"
#include "Page.hpp"
#include "Session.hpp"
namespace CppCanvas {
    class Canvas
    {
        private:
            std::string token;
            std::string base_url;
            CppCanvas::Session session;

        public:
        //overloaded constructors
            Canvas (const CppCanvas::Session& _session) :
            session (_session), token(_session.token), base_url(_session.url) {}
            //member functions
            //PageList GetPagesList (const std::string& _url)
            //{
            //    return 
            //}
            CppCanvas::Page GetPage (const std::string& _url)
            {
                CppCanvas::RequestHandler requests (session);
                CppCanvas::RequestOptions options (_url, true, true);
                CppCanvas::HttpObject response = requests.GetRequest(options);
                CppCanvas::Page response_page (response);
                return response_page;
            }


    };

}
