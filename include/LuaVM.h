#ifndef _LUAVM_
#define _LUAVM_

extern "C" {
    #include <lua.h>
    #include <lauxlib.h>
    #include <lualib.h>
}

#include <iostream>
#include <LuaBridge/LuaBridge.h>

//#include <luabind/luabind.hpp>
/*
void hello();

#ifdef _WIN32
    extern "C" __declspec(dllexport) int init(lua_State* L);
#else
    extern "C" int init(lua_State* L);
#endif
*/
class LuaVM {
        lua_State *lua;
        char buffer[256];
        int error;
    public:
        LuaVM();
        ~LuaVM();
        void lua_function();
        void script(std::string filename);
        void shell();
        std::string execute(std::string command);
};

#endif // _LUAVM_
