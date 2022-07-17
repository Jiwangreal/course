cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
project(hellocpp LANGUAGES CXX)
# set(CMAKE_CXX_FLAGS "-g")
# list(APPEND CMAKE_CXX_FLAGS )
# set(CMAKE_CXX_FLAGS ${CXX_FLAGS})



set(CXX_FLAGS "-Wall")
list(APPEND CXX_FLAGS "-g")
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")
add_executable(cpptest main.cpp)
