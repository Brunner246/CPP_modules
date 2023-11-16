cmake_minimum_required(VERSION 3.26)
project(ModulesTest)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /experimental:module /std:c++latest")

add_library(${PROJECT_NAME}
        src/ModuleOne.ixx
        src/Math_demo.ixx
        src/MathAlgebra.ixx
        src/MathGeometry.ixx
        src/Math.ixx
        src/Character.ixx
        src/Character.cpp
)