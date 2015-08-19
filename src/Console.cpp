#include "Console.h"

Console::Console(Window *window) : window(window), visible(true), size(20), text_color(0xA4A5FF99), background(0x4242E799), row(0) {

    SDL_DisplayMode display;
    SDL_GetWindowDisplayMode(window->getWindow(), &display);

    luavm = new LuaVM();

    margin = display.w/100;

    rect.x = margin;
    rect.y = display.h/3;
    rect.w = display.w - 2 * margin;
    rect.h = display.h - margin - rect.y;

    lines = rect.h / size;

    text = new Fonts(window, "C-64.ttf", size);
/*    
    text_buffer.push_back(".--------------------------------------------------------------------------------------.");
    text_buffer.push_back("|''':''''|'''':''''|'''':''''|'''':''''|'''':''''|'''':''''|'''':''''|'''':''''|'''':''|");
    text_buffer.push_back("|       10        20        30        40        50        60        70        80       |");
    text_buffer.push_back("|______________________________________________________________________________________|");

    text_buffer.push_back("Margin: " + std::to_string(margin));
    text_buffer.push_back("X: " + std::to_string(rect.x));
    text_buffer.push_back("Y: " + std::to_string(rect.y));
    text_buffer.push_back("W: " + std::to_string(rect.w));
    text_buffer.push_back("H: " + std::to_string(rect.h));
    text_buffer.push_back("Lines: " + std::to_string(lines));
    text_buffer.push_back("Width/88: "+ std::to_string(rect.w / 88));
    text_buffer.push_back("Width/size: " + std::to_string(rect.w / size));
    text_buffer.push_back("size * 88: " + std::to_string(size * 88));


    text_buffer.push_back("    **** COMMODORE 64 BASIC V2 ****     ");
    text_buffer.push_back(" 64K RAM SYSTEM  38911 BASIC BYTES FREE ");
    text_buffer.push_back("READY.");
*/
    text_buffer.push_back("  **** Beleza Game Engine Console ****  ");
    text_buffer.push_back(" Copyright (c) 2014 by Michael Borgmann ");
    text_buffer.push_back(" Commands: help lua load bugs");
    text_buffer.push_back(" READY.");
}

Console::~Console() {
    delete luavm;
}

void Console::draw() {
    if (visible) {
        Uint8 r = (background & 0xff000000) / 0x1000000;
        Uint8 g = (background & 0xff0000) / 0x10000;
        Uint8 b = (background & 0xff00) / 0x100;
        Uint8 a = background & 0xff;
        SDL_SetRenderDrawBlendMode(window->getRenderer(), SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(window->getRenderer(), r, g, b, a);
        SDL_RenderFillRect(window->getRenderer(), &rect);
        show_text_buffer();
        show_prompt();
    }
}

bool Console::toggle_visibility() {
    visible = !visible;
    return visible;
} 

bool Console::is_visible() {
    return visible;
}

void Console::show_text_buffer() {
    row = 0;
    int offset = text_buffer.size() > lines ? text_buffer.size() - lines : -1;
    for (int line = offset + 1; line < text_buffer.size(); line++) {
        text->print(text_buffer[line], rect.x, rect.y + row++ * size, text_color);
    }
}

void Console::show_prompt() {
    prompt = "> ";
    prompt += input;
    text->print(prompt.c_str(), rect.x, rect.y + row++ * size, text_color);
}

void Console::render_input(std::string input) {
    this->input = input;
}

void Console::execute_command() {

    //std::string run_script = "Demo.app/Contents/Resources/script.lua";
    std::string run_script = "script.lua";

    text_buffer.push_back(prompt);

    if (input == "help\0") {
        text_buffer.push_back("Beleza In-Game Console");
        text_buffer.push_back("Copyright (c) 2014 by Michael Borgmann");
        text_buffer.push_back("Commands: help lua load bugs");
    }
    else if (input == "lua\0") {
        text_buffer.push_back("Lua integration:");
        text_buffer.push_back("    - call Lua functions from C/C++");
        text_buffer.push_back("    - call C/C++ functions from Lua");
        text_buffer.push_back("    - execute Lua commands in Shell");
        text_buffer.push_back("    - run Lua scripts");
        text_buffer.push_back("Default Lua Script:");
        text_buffer.push_back("dofile (\"" + run_script + "\")");
        text_buffer.push_back("... simply execute it with load ;)");
    }
    else if (input == "load\0") {
        text_buffer.push_back("LOAD \"script.lua\",8,1");
        luavm->script(run_script);
    }
    else if (input == "bugs\0") {
        text_buffer.push_back("- Run Demo.app at Debug/");
        text_buffer.push_back("- Load only works once");
    }
    else if (input != "") {
        std::string output = luavm->execute(input);
        if (output != "")
            text_buffer.push_back(output.c_str());
    }
    input = "";
}
