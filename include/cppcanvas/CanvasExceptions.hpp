#pragma once
#include <iostream>
#include <exception>
namespace CppCanvas {
    namespace api_errors
    {
        struct PageNotFound : public std::exception {
            const char * what () const throw () 
            {
                return "Canvas API Error: Page not found";
            }
        };

        struct BadRequest : public std::exception {
            const char * what () const throw () 
            {
                return "Canvas API Error: Bad Request";
            }
        };
    }
    namespace json_errors
    {
        struct BadJsonKey : public std::exception {
            const char* what () const throw ()
            {
                return "Canvas JSON Error: JSON object doesn't contain the specified attribute";
            }
        };
    }
        
}
