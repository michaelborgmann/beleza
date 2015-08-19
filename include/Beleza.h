#ifndef _BELEZA_H_
#define _BELEZA_H_

#include <iostream>
#include "SDL2.h"
#include "Window.h"
#include "Image.h"
#include "Starfield3D.h"
#include "Music.h"
#include "Console.h"
#include "Fonts.h"

class Beleza {
    private:
        int scale;
        Window *window;
        Image *image;
        Starfield3D *starfield;
        Music *song;
        Console *console;
        SDL_Event event;
        bool render_text;
        std::string input;

        bool init_audio_video();
        bool init_bitmaps();
        bool init_fonts();
        bool init_subsystems();
        bool free_subsystems();
        void render();
        void mainloop();

    public:
        Beleza(std::string title = "Beleza", std::string release = "0.0.3");
        ~Beleza();
};

#endif
