#pragma once
#include <iostream>
#include <string>
#include <map>
#include <json.hpp>
#include "HttpObject.hpp"
#include "CanvasExceptions.hpp"
#include "CanvasElement.hpp"
#include "RequestHandler.hpp"
#include "Attributes.hpp"
typedef nlohmann::json  json;
namespace CppCanvas {
    class PageRevision : public CanvasElement {
        using CanvasElement::CanvasElement;
    };


    class Page : public CanvasElement{
        using CanvasElement::CanvasElement;
        public: 
            PageRevision GetLatestRevision () 
            {
                
            }
    };

}
