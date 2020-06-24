#include <iostream>
#include <exception>
namespace api_errors
{
    struct PageNotFound : public std::exception {
        const char * what () const throw () 
        {
            return "Canvas Error: Page not found";
        }
    };

    struct BadRequest : public std::exception {
        const char * what () const throw () 
        {
            return "Canvas Error: Bad Request";
        }
    };
}
    