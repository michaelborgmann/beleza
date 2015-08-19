#include <iostream>
#include <string>
#include "LuaVM.h"

LuaVM::LuaVM(){
    std::cout << "LuaVM Start\n";
    lua = luaL_newstate();
    luaL_openlibs(lua);
}

LuaVM::~LuaVM(){
    std::cout << "LuaVM Stop\n";
    lua_close(lua);
}

void LuaVM::lua_function() {
/*
    std::cout << "Execute Lua Function\n";
    luabind::open(lua);
    luaL_dostring(lua,
                  "function add(first, second)\n"
                  "    return first + second\n"
                  "end\n");

    std::cout << "Result: "
              << luabind::call_function<int>(lua, "add", 4, 3)
              << '\n';
*/
}

void LuaVM::script(std::string filename) {
    std::cout << "** Lua Script '" << filename << "'\n";
    if (luaL_dofile(lua, filename.c_str()) == 1) {
        std::cout << "No Lua file\n";
    }
}

void LuaVM::shell() {
/*
    std::cout << "** Lua Shell\n\n";
    std::string input;
    int done = false;
    while (!done) {
        std::cout << "> ";
        std::getline (std::cin, input);
        if (input.empty()) done = true;
        error = luaL_loadstring(lua, input.c_str()) || lua_pcall(lua, 0, 0, 0);
        if (error) {
            std::cerr << stderr << lua_tostring(lua, -1) << '\n';
            lua_pop(lua, 1);
        }
    }
*/
}

std::string LuaVM::execute(std::string command) {
    error = luaL_loadstring(lua, command.c_str()) || lua_pcall(lua, 0, 0, 0);
    if (error) {
        std::cerr << stderr << lua_tostring(lua, -1) << '\n';
        lua_pop(lua, 1);
    }
    return "";
}

/*
void hello() {
    std::cout << "Hello World!\n";
}

//extern "C" __declspec(dllexport) int init(lua_State* L) {
extern "C" int init(lua_State* L) {
    luabind::open(L);
    luabind::module(L) [luabind::def("hello", &hello)];
    return 0;
}
*/
