#pragma once
#include <iostream>
#include <string>
#include <map>
#include <json.hpp>
#include "HttpObject.hpp"
#include "CanvasExceptions.hpp"

typedef nlohmann::json  json;

class Page {
    public:
        std::string url, 
                    title, 
                    created_at, 
                    updated_at, 
                    editing_roles, 
                    last_edited_by_name,
                    lock_info,
                    lock_explanation,
                    raw_body;
        int id, last_edited_by_id;
        bool locked_for_user, 
             published,
             front_page;
        std::map <std::string, std::string> fmt_header;

        Page (const HttpObject& http) :
            fmt_header (http.fmt_header), raw_body (http.GetRawBody()) 
        {
            try {
                json fmt_body = json::parse (raw_body);

                if (fmt_body.contains("message")) 
                {
                    throw api_errors::PageNotFound();
                    return;
                } else {

                    url = fmt_body["html_url"];
                    id = fmt_body["page_id"];
                    title = fmt_body["title"];
                    created_at = fmt_body["created_at"];
                    updated_at = fmt_body["updated_at"];
                    editing_roles = fmt_body["editing_roles"];
                    published = fmt_body["published"];
                    front_page = fmt_body["front_page"];
                    locked_for_user = fmt_body["locked_for_user"];

                    if (locked_for_user)
                    {
                        lock_info = fmt_body["lock_info"];
                        lock_explanation = fmt_body["lock_explanation"];
                    }
                    if (fmt_body.contains("last_edited_by"))
                    {
                        last_edited_by_name = fmt_body["last_edited_by"]["display_name"];
                        last_edited_by_id = fmt_body["last_edited_by"]["id"];
                    }
                        
                    
                }
            } catch (const std::exception& e) {
                std::cerr << e.what() << "\n";
            }
            
        }
        
};
class PageRevision {
    public: 
        
}
struct PageOptions {
     
};
