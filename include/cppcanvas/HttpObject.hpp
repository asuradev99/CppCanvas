#pragma once
#include <iostream>
#include <string> 
#include <vector>
#include <sstream>
#include <map>

namespace CppCanvas {
    class HttpObject 
    {
        private:
            std::string raw_contents;
            std::string raw_header;
            std::string raw_body;
            
        public:
            std::map <std::string, std::string> fmt_header;
            std::map<std::string, std::string> ParseHttpHeader (std::string _raw_header) 
            {
                size_t hdr_end = raw_contents.find("\r\n\r\n");
                if (hdr_end != std::string::npos)
                {
                    raw_header = raw_contents.substr(0, hdr_end);
                    raw_body = raw_contents.substr(hdr_end + 4);
                }
                size_t sub = _raw_header.find("\r\n");
                std::vector<std::string> temp;
                while (sub != std::string::npos)
                {
                    temp.emplace_back (_raw_header.substr(0,sub));
                    _raw_header.erase (0,sub + 2);
                    sub = _raw_header.find("\r\n");
                }
                std::map <std::string, std::string> output;
                for (auto& x : temp)
                {
                    std::string temp_key;
                    std::string temp_value;

                    sub = x.find(":");
                    if (sub != std::string::npos)
                    {
                        temp_key =  x.substr(0, sub);
                        temp_value = x.substr(sub + 1);
                    } else {
                        temp_key = x;
                        temp_value = "";
                    }
                    output [temp_key] = temp_value;
                }
                return output;
            }
            HttpObject () {}
            HttpObject (const std::string& _raw_contents) :
                raw_contents(_raw_contents) 
            {
                fmt_header = ParseHttpHeader(raw_header);
            }
            
            std::string GetRawContents () const 
            {
                return raw_contents;
            }
            std::string GetRawHeader () const
            {
                return raw_header;
            }
            std::string GetRawBody () const
            {
                return raw_body;
            }
                
    };   
}
