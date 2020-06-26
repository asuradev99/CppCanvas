#pragma once
#include <iostream>
#include <string>
#include <map>
#include <json.hpp>
#include "HttpObject.hpp"
#include "CanvasExceptions.hpp"
#include "ParsedElement.hpp"

typedef nlohmann::json  json;


class Page : public ParsedElement{
    using ParsedElement::ParsedElement;
};
class PageRevision {
    public: 

};
