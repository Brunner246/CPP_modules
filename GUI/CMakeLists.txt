cmake_minimum_required(VERSION 3.26)
project(GUI)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /experimental:module")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

SET(CADLIB_DIR "C:/source/cadlib")

set(CADWORK_VERSION 30)

set(CMAKE_PREFIX_PATH "${CADLIB_DIR}3rdParty/v_${CADWORK_VERSION}.0/Qt/x64/lib/cmake")

INCLUDE_DIRECTORIES("${CADLIB_DIR}/v_${CADWORK_VERSION}.0/3d/CwAPI3D")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_library(${PROJECT_NAME}
        src/cmainwindow.cpp
        src/cmainwindow.h
        src/cmainwindow.ui
        src/gui_api.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
        GUI_LIBRARY
)