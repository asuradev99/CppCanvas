#pragma once
#include <iostream>
#include <string> 
#include <vector>
#include <sstream>

class HttpObject 
{
    private:
        std::string raw_contents;
        std::string raw_header;
        std::string raw_body;

        std::string fmt_header;
        std::string fmt_body;
    public:
        HttpObject () {}
        HttpObject (const std::string& _raw_contents) :
            raw_contents(_raw_contents) 
        {
            
        }
        void SeparateContents ()
        {
            size_t hdr_end = raw_contents.find("\r\n\r\n");
            if (hdr_end != std::string::npos)
            {
                raw_header = raw_contents.substr(0, hdr_end);
                raw_body = raw_contents.substr(hdr_end + 4);
            }
        }
        std::string GetRawContents ()
        {
            return raw_contents;
        }
        std::string GetRawHeader ()
        {
            return raw_header;
        }
        std::string GetRawBody () 
        {
            return raw_body;
        }
        std::vector<std::string> ParseHttpHeader (std::string _raw_header) 
        {
            size_t sub = _raw_header.find("\r\n");
            std::vector<std::string> output;
            while (sub != std::string::npos)
            {
                
                output.emplace_back (_raw_header.substr(0,sub));
                _raw_header.erase (0,sub + 2);
                sub = _raw_header.find("\r\n");
            }
            return output;
        }
};