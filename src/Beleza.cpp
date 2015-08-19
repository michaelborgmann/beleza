#include "Beleza.h"

Beleza::Beleza(std::string title, std::string release) {
    std::cout << "Welcome to " << title << " " << release << std::endl;
    if (init_subsystems()) {

        SDL_Rect rect;
        SDL_GetDisplayBounds(0, &rect);

        scale = rect.w * 100 / 1920;

        window = new Window(rect.w, rect.h);
        SDL_ShowCursor(0);

        // load assets
        image = new Image(window, "ShootOrDie.png");
        starfield = new Starfield3D(window, 10000);
        song = new Music("BeamsOfLight.ogg");
        song->play();
        console = new Console(window);

        if (window) mainloop();
    }
}

Beleza::~Beleza() {
    delete song;
    delete starfield;
    delete image;

    free_subsystems();
    std::cout << "Greetz fly to Gandhi, Mandela, Buddha, ...\n";
}

bool Beleza::init_audio_video() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }
    std::cout << "[X] Video\n";
    std::cout << "[X] Audio\n";
    return true;
}

bool Beleza::init_bitmaps() {
    int flags = IMG_INIT_PNG;       // IMG_INIT_JPG|IMG_INIT_PNG
    if ((IMG_Init(flags) & flags) != flags) {
        std::cerr << "IMG Error: " << IMG_GetError() << std::endl;
        return false;
    }
    std::cout << "[X] Bitmaps\n";
    return true;
}

bool Beleza::init_fonts() {
    if (TTF_Init() < 0) {
        std::cerr << "TTF Error: " << TTF_GetError() << std::endl;
        return false;
    }
    std::cout << "[X] Fonts\n";
    return true;
}

bool Beleza::init_subsystems() {

    std::cout << "Setup Subsstems\n"
                 "---------------\n";
    if (!init_audio_video() || !init_bitmaps() || !init_fonts()) {
        std::cerr << "Couldn't setup subsystems\n";
        return false;
    }
    return true;
}

bool Beleza::free_subsystems() {
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Beleza::mainloop() {
    bool done = false;
    SDL_StartTextInput();
    while (!done) {
        render_text = false;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                //case SDL_FINGERDOWN:
                case SDL_QUIT:
                    done = true;
                    break;
                case SDL_KEYDOWN : 
                    switch (event.key.keysym.sym) {
                        case SDLK_TAB:
                            console->toggle_visibility();
                            if (console->is_visible()) SDL_StartTextInput();
                            else SDL_StopTextInput();
                            break;
                        case SDLK_ESCAPE:
                            done = true;
                            break;
                        case SDLK_BACKSPACE:
                            if (console->is_visible()) {
                                if (input.length() > 0) {
                                    input.pop_back();
                                    render_text = true;
                                }
                            }
                            break;
                        case SDLK_RETURN:
                            if (console->is_visible()) {
                                console->execute_command();
                                input = "";
                            }
                            break;
                    }
                case SDL_TEXTINPUT:
                    if (event.text.text[0] != 1) {
                        input += event.text.text;
                        render_text =  true;
                    }
                    break;
            }
        }
        render();
    }
}

void Beleza::render() {
    SDL_SetRenderDrawColor(window->getRenderer(), 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(window->getRenderer());
    starfield->draw();
    image->draw(window->width()/2 - image->width()/2 * scale/100, 10, scale);
    console->draw();
    if (render_text) console->render_input(input);
    SDL_RenderPresent(window->getRenderer());
    SDL_Delay(20);
}
