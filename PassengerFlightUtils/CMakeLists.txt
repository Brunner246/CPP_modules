cmake_minimum_required(VERSION 3.26)
project(PassengerFlightUtils)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /experimental:module")

add_library(${PROJECT_NAME}
        src/IPerson.ixx
        src/CPerson.ixx
)