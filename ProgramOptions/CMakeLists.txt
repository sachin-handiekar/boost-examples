cmake_minimum_required(VERSION 3.3)

set(CMAKE_OSX_ARCHITECTURES "x86_64")

project(ProgramOptions)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lboost_program_options")

find_package(Boost 1.47 COMPONENTS filesystem unit_test_framework REQUIRED)

message(status "** Boost Include: ${Boost_INCLUDE_DIR}")
message(status "** Boost Libraries: ${Boost_LIBRARY_DIRS}")
message(status "** Boost Libraries: ${Boost_LIBRARIES}")


set(SOURCE_FILES main.cpp)
add_executable(ProgramOptions ${SOURCE_FILES})