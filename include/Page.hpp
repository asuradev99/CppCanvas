#pragma once
#include <iostream>
#include <string>
#include <map>

class Page {
    private:
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
    public:
        

};
