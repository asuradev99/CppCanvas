cmake_minimum_required(VERSION 3.16)
project(CppCanvas VERSION 1.0 
                  DESCRIPTION "A c++ wrapper for Canvas's LMS REST API"
                  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable (
    simple_page "examples/simple_page.cpp"

)

link_directories("/usr/lib/x86_64-linux-gnu/")
target_link_libraries(simple_page -lcurl -lcurlpp)

