#pragma once
#include <iostream>
#include <string> 
#include <vector>
class HttpObject 
{
    private:
        std::string contents;
        std::string header;
        std::string body;
    public:
        HttpObject () {}
        HttpObject (const std::string& _contents) :
        contents(_contents) 
        {
            
        }
        void SeparateContents ()
        {
            size_t hdr_end = contents.find("\r\n\r\n");
            if (hdr_end != std::string::npos)
            {
                header = contents.substr(0, hdr_end);
                body = contents.substr(hdr_end + 4);
            }
        }
        std::string GetContents ()
        {
            return contents;
        }
        std::string GetHeader ()
        {
            return header;
        }
        std::string GetBody () 
        {
            return body;
        }
};