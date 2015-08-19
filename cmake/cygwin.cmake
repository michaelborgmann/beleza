if (CYGWIN)
    message ("Build for Cygwin")
    set (BUILD_FLAGS WIN32)
    set (CMAKE_CXX_FLAGS "-Wl,-u,_WinMain@16")
    include (FindSDL2)
    include_directories (${HEADERS} /usr/local/include)
    link_directories(/usr/local/lib)
    link_libraries(${SDL2_LIBRARY} SDL2_image SDL2_ttf SDL2_mixer lua)
    set (LIBS)
endif ()
