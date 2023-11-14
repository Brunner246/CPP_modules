cmake_minimum_required(VERSION 3.26)
project(CPP_modules)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /experimental:module")

add_subdirectory(ModulesTest)
add_subdirectory(PassengerFlightUtils)
add_subdirectory(GUI)

add_executable(${PROJECT_NAME}
        src/main.cpp
)

target_link_libraries(${PROJECT_NAME}
        ModulesTest
        PassengerFlightUtils
        GUI
)
