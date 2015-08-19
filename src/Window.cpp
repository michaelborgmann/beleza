#include "Window.h"

Window::Window(int width, int height) : w(width), h(height), window(nullptr), renderer(nullptr) {
    if (!create_window(width, height)) exit(1);
}

Window::~Window() {}

bool Window::create_window(int width, int height) {
    SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP, &window, &renderer);
    if (!window || !renderer) {
        std::cerr << "SDL Error: " << SDL_GetError() << '\n';
        return false;
    }
    SDL_SetHint(SDL_HINT_ORIENTATIONS, "LandscapeRight");
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, width, height);
    std::cout << "[X] Rendering Window\n";



    return true;
}

SDL_Renderer* Window::getRenderer() { return renderer; }
SDL_Window* Window::getWindow() { return window; }
int Window::width() { return w; }
int Window::height() { return h; }
