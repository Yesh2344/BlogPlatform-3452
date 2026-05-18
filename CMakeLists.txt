cmake_minimum_required(VERSION 3.10)
project(BlogPlatform)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(cpp-filesystem REQUIRED)
find_package(nlohmann_json REQUIRED)

add_executable(blog-platform main.cpp utils.cpp config.cpp logger.cpp post.cpp database.cpp)
target_link_libraries(blog-platform PRIVATE cpp-filesystem::cpp-filesystem nlohmann_json::nlohmann_json)

add_test(NAME blog-platform-test COMMAND blog-platform-test)
add_executable(blog-platform-test test.cpp utils.cpp config.cpp logger.cpp post.cpp database.cpp)
target_link_libraries(blog-platform-test PRIVATE cpp-filesystem::cpp-filesystem nlohmann_json::nlohmann_json)

