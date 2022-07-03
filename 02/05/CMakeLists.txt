cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
set(CXX_FLAGS "-g" "-Wall")
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")
project(hellocpp LANGUAGES CXX)

add_executable(cpptest main.cpp)
