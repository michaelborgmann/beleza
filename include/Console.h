#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <vector>
#include "SDL2.h"
#include "Window.h"
#include "Fonts.h"
#include "LuaVM.h"

class Console {
    private:
        Window *window;
        Fonts *text;
        LuaVM *luavm;
        SDL_Rect rect;
        bool visible;
        short margin;
        short size;
        Uint32 text_color;
        Uint32 background;
        short lines;
        std::vector<std::string> text_buffer;
        int row;
        std::string input;
        std::string prompt;

        void show_text_buffer();
        void show_prompt();

    public:
        Console(Window *window);
        ~Console();
        void draw();
        bool toggle_visibility();
        void render_input(std::string input);
        void execute_command();
        bool is_visible();
};

#endif
