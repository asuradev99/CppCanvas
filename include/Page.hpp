#pragma once
#include <iostream>
#include <string>
#include <map>
#include <json.hpp>
#include "HttpObject.hpp"

typedef nlohmann::json  json;

class Page {
    public:
        std::string url, 
                    title, 
                    created_at, 
                    updated_at, 
                    editing_roles, 
                    last_edited_by, 
                    published, 
                    front_page, 
                    locked_for_user, 
                    lock_info, 
                    lock_explanation;
        std::string raw_body;
        std::map <std::string, std::string> fmt_header;
        json fmt_body;
        Page (const HttpObject& http) :
            fmt_header (http.fmt_header), raw_body (http.GetRawBody()) 
        {
            fmt_body = json::parse (raw_body);
            for (auto x : fmt_header) {
                std::cout << x.second << "\n";
            }
            std::cout << fmt_body;
        }
        
};
struct PageOptions {
     
};
