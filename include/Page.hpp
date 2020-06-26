#pragma once
#include <iostream>
#include <string>
#include <map>
#include <json.hpp>
#include "HttpObject.hpp"
#include "CanvasExceptions.hpp"

typedef nlohmann::json  json;
enum class PageAttributes : std::string {
    url = "html_url",
    id = "page_id",
    title = "title",
    body = "body",
    created_at = "created_at",
    updated_at = "updated_at",
    editing_roles = "editing_roles",
    published = "published",
    front_page = "front_page",
    locked_for_user = "locked_for_user",    
};

class Page {
    private:
        std::map <std::string, std::string> parsed_header;
        std::string raw_body;
        json json_body;
    public: 
        Page (const HttpObject& http) :
            parsed_header (http.fmt_header), raw_body (http.GetRawBody()) 
        {
            try {
                json_body = json::parse (raw_body);

                if (json_body.contains("message")) 
                {
                    throw api_errors::PageNotFound();
                    return;
                }
            } catch (const std::exception& e) {
                std::cerr << e.what() << "\n";
            }
            
        }
        auto get (const std::string& key) {
            return json_body[key];
        }
  
};
class PageRevision {
    public: 

};
