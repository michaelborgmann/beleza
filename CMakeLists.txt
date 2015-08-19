cmake_minimum_required(VERSION 2.8.9)
project (BELEZA) 

add_definitions (-std=c++11)

set (BELEZA ${BELEZA_SOURCE_DIR})
set (SOURCES ${BELEZA}/src)
set (HEADERS ${BELEZA}/include)
set (SHARE ${BELEZA}/share)
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${BELEZA}/cmake/Modules)

include(cmake/resources.cmake)
include (cmake/macosx.cmake)
include (cmake/ios.cmake)
include (cmake/cygwin.cmake)

add_library (DemoFX ${SOURCES}/Starfield3D.cpp)

add_library (Beleza
    ${SOURCES}/Beleza.cpp
    ${SOURCES}/Window.cpp
    ${SOURCES}/Image.cpp
    ${SOURCES}/Music.cpp
    ${SOURCES}/Fonts.cpp
    ${SOURCES}/Console.cpp
    ${SOURCES}/LuaVM.cpp
)
target_link_libraries (Beleza DemoFX)

add_executable (Demo ${BUILD_FLAGS} ${SOURCES}/Main.cpp ${RESOURCES})
target_link_libraries (Demo ${LIBS} Beleza)
