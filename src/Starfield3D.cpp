#include "Starfield3D.h"

Starfield3D::Starfield3D(Window *window, int stars) : TOTAL_STARS(stars), window(window) {
    srand(time(0));

    for (int i = 0; i < TOTAL_STARS; i++) {
        starfield.push_back(std::vector<int>(3));
        starfield[i][0] = rand() % window->width() - window->width() / 2;
        starfield[i][1] = rand() % window->height() - window->height() / 2;
        starfield[i][2] = rand() % DISTANCE;
    }
}

void Starfield3D::draw() {
    for (int i = 0; i < TOTAL_STARS; i++) {
        starfield[i][2] -= 1;
        if (starfield[i][2] <= 0) starfield[i][2] = DISTANCE;
        int x = ((starfield[i][0] * SCALE) / starfield[i][2]) + window->width() / 2;
        int y = ((starfield[i][1] * SCALE) / starfield[i][2]) + window->height() / 2;
        if (x > 0 && x < window->width() && y > 0 && y < window->height()) {
            int color = WHITE - (SHADE * starfield[i][2]);
            SDL_SetRenderDrawColor(window->getRenderer(), color, color, color, 0xff);
            SDL_RenderDrawPoint(window->getRenderer(), x, y);
        }
    }
}
