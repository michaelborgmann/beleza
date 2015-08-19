#ifndef _MUSIC_H_
#define _MUSIC_H_

#include <iostream>
#include "SDL2.h"

class Music {
    private:
        Mix_Music *music;
    public:
        Music(std::string filename);
        ~Music();
        void play();
};

#endif
