#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <iostream>
#include "SDL2.h"
#include "Window.h"

class Image {
    private:
        int w, h;
        Window *window;
        SDL_Surface *bitmap;
        SDL_Texture *texture;
    public:
        Image(Window *window, std::string filename);
        ~Image();
        void draw(int x, int y, int scale = 100);
        int width();
        int height();
};

#endif
