#ifndef _STARFIELD3D_H_
#define _STARFIELD3D_H_

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "SDL2.h"
#include "Window.h"

class Starfield3D {
    private:
        const int TOTAL_STARS;
        int width, height;
        Window *window;
        enum attributes { BLACK = 0x00, WHITE = 0xff, SHADE = 0x01, DISTANCE = 0xff, SCALE = 0xff };
        std::vector< std::vector<int> > starfield;
    public:
        Starfield3D(Window *window, int star);
        void draw();
};

#endif
