cmake_minimum_required (VERSION 2.6)
SET(CMAKE_CXX_FLAGS "--std=c++14") #Turn on C++14 Support
include_directories(include)


add_executable(executable 
    /home/przemo/List/code/include/list.hpp
    ../main.cpp
        )
