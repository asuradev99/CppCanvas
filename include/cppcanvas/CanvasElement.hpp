#pragma once
#include <iostream>
#include <string>
#include <map>
#include <json.hpp>
#include "HttpObject.hpp"
#include "CanvasExceptions.hpp"
#include "Attributes.hpp"
#include "Session.hpp"

typedef nlohmann::json  json;
typedef nlohmann::basic_json<> json_element;

namespace CppCanvas {
	struct json_return_type
	{
		
		json_element elem;
		template<typename T>
		operator T() const   //implicitly convert into T
		{
			T converted_value = elem;
			return converted_value;  
		}
		friend std::ostream& operator <<(std::ostream& os, const json_return_type& val);
	};
	std::ostream& operator <<(std::ostream& os, const json_return_type& val) 
	{
		if (val.elem.is_string()) {
			os << std::string(val.elem);
		}
		else if (val.elem.is_number_integer()) {
			os << int(val.elem);
		}
		else if (val.elem.is_boolean()) {
			os << bool(val.elem);
		}
		
		return os;
	}
	class CanvasElement{
		protected:
			std::map <std::string, std::string> parsed_header;
			std::string raw_body;
			Session session;
			json json_body;
		public: 
			CanvasElement (const HttpObject& http, const Session& _session) :
				parsed_header (http.fmt_header), raw_body (http.GetRawBody()), session(_session) 
			{
				try {
					
					for (auto& [key, value] : parsed_header) {
						std::cout << key << " : " << value << "\n"; 
					}
					json_body = json::parse (raw_body);
					std::cout << json_body << "\n";
					if (json_body.contains("message")) 
					{
						throw api_errors::PageNotFound();
						return;
					}

				} catch (const std::exception& e) {
					std::cerr << e.what() << "\n";
				}
				
			}  
			json_return_type get (const Attribute& attr) {
				
				try {
					json_element elem;
					if (attr.container == "") {
						if (json_body.contains(attr.key)) {
							elem = json_body[attr.key];
						} else {
							throw json_errors::BadJsonKey();
						}
					} else {
						if (json_body.contains (attr.container)) {
							if (json_body[attr.container].contains(attr.key)) {
								elem = json_body[attr.container][attr.key];
							} else {
								throw json_errors::BadJsonKey();
							}
						} else {
							throw json_errors::BadJsonKey();
						}
					}
					if (elem.is_null()) {
						return {"null"};
					}
					else if (elem.is_string()){
						std::string escaped_output = std::string(elem);
						return {escaped_output};
					}
					return {elem};
					
				} catch (const std::exception& e) {
					return {e.what()};
				}
				
			}
	};
}
