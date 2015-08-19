#include "Image.h"

Image::Image(Window *window, std::string filename) : window(window) {
    bitmap = IMG_Load(filename.c_str());
    if (!bitmap) {
        std::cerr << "IMG Error: " << IMG_GetError() << std::endl;
        exit(1);
    }

    texture = SDL_CreateTextureFromSurface(window->getRenderer(), bitmap);
    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    w = bitmap->w;
    h = bitmap->h;
    SDL_FreeSurface(bitmap);
}

Image::~Image() {
    if (texture) SDL_DestroyTexture(texture);
}

void Image::draw(int x, int y, int scale) {
    SDL_Rect position = {x, y, w * scale/100, h * scale/100};
    SDL_RenderCopy(window->getRenderer(), texture, NULL, &position);
}

int Image::width() { return w; }
int Image::height() { return h; }
