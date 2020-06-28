#pragma once
#include <string>
namespace CppCanvas {
    struct Attribute {
        std::string container;
        std::string key;
        Attribute (const std::string& _key) : container(""), key (_key) {}
        Attribute (const std::string& _container, const std::string& _key) : container(_container), key (_key) {}
    };
    namespace Attributes {
        namespace Page 
        {
            Attribute   url ("html_url"),
                        id ("page_id"),
                        title ("title"),
                        body ("body"),
                        created_at ("created_at"),
                        updated_at ("updated_at"),
                        editing_roles ("editing_roles"),
                        published ("published"),
                        front_page ("front_page"),
                        locked_for_user ("locked_for_user"),
                        lock_info ("lock_info"),
                        lock_explanation ("lock_explanation");
            namespace last_edited_by {
                Attribute   avatar_image_url ("last_edited_by", "avatar_image_url"), 
                            display_name ("last_edited_by","display_name"), 
                            html_url ("last_edited_by","html_url"),
                            id ("last_edited_by","id"),
                            pronouns ("last_edited_by","pronouns");
            }
        }
        namespace PageRevision {
            Attribute   revision_id ("revision_id"),
                        updated_at ("updated_at"),
                        latest ("latest"),
                        url ("url"),
                        title ("title"),
                        body ("body");
            namespace edited_by {
                Attribute   avatar_image_url ("last_edited_by", "avatar_image_url"), 
                            display_name ("last_edited_by","display_name"), 
                            html_url ("last_edited_by","html_url"),
                            id ("last_edited_by","id"),
                            pronouns ("last_edited_by","pronouns");
            }
        }

    }
}
