cmake_minimum_required(VERSION 2.6)
SET(CMAKE_CXX_FLAGS "--std=c++14") #Turn on C++14 Support
#include files to test
include_directories(/home/przemo/List/tests/googletest/googletest/include)
add_executable(utest test.cpp )
target_link_libraries(utest /home/przemo/List/tests/googletest/googletest/libgtest.a pthread)
