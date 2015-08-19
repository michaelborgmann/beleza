#include "Music.h"

Music::Music(std::string filename) {
    music = Mix_LoadMUS(filename.c_str());
    if (!music) {
        std::cerr << "Mix Error: " << Mix_GetError() << std::endl;
        exit(1);
    }
    Mix_OpenAudio(441000, MIX_DEFAULT_FORMAT, 2, 2048);
}

Music::~Music() {
    Mix_FreeMusic(music);
    Mix_CloseAudio();
}

void Music::play() {
    Mix_PlayMusic(music, -1);
}
