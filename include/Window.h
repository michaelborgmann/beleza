#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <iostream>
#include "SDL2.h"

class Window {
    private:
        int w, h;
        SDL_Window *window;
        SDL_Renderer *renderer;
        bool create_window(int width, int height);
    public:
        Window(int width = 320, int height = 240);
        ~Window();
        SDL_Window* getWindow();
        SDL_Renderer* getRenderer();
        int width();
        int height();
};

#endif
