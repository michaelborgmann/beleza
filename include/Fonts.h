#ifndef _FONTS_H_
#define _FONTS_H_

#include "SDL2.h"
#include "Window.h"

class Fonts {
    private:
        Window* window;
        TTF_Font* font;
    public:
        Fonts(Window *window, std::string filename, short size);
        ~Fonts();
        void print(std::string text, int x, int y, Uint32 color);
};

#endif
