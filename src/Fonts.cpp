#include <cstdlib>
#include "Fonts.h"

Fonts::Fonts(Window *window, std::string filename, short size) : window(window) {
    font = TTF_OpenFont(filename.c_str(), size);
    if (!font) {
        std::cerr << "TTF Error: " << TTF_GetError() << std::endl;
        exit(1);
    }
}

Fonts::~Fonts() {}

void Fonts::print(std::string text, int x, int y, Uint32 color) {
    Uint8 r = (color & 0xff000000) / 0x1000000;
    Uint8 g = (color & 0xff0000) / 0x10000;
    Uint8 b = (color & 0xff00) / 0x100;
    Uint8 a = (color & 0xff);
    SDL_Color rgba = { r, g, b, a};
    SDL_Surface *bitmap = TTF_RenderText_Solid(font, text.c_str(), rgba);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(window->getRenderer(), bitmap);
    SDL_Rect position = {x, y, bitmap->w, bitmap->h};
    SDL_FreeSurface(bitmap);
    SDL_RenderCopy(window->getRenderer(), texture, NULL, &position);
}
