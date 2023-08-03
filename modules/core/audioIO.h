// Mic Listener
// Created by Ethan Edwards on 8/2/2023.
//

#ifndef PERSONALASSISTANT_AUDIOIO_H
#define PERSONALASSISTANT_AUDIOIO_H

#include <SDL_audio.h>
#include <atomic>
#include <SDL.h>

using namespace std;

class audioIO { // I'm in your walls
public:
    audioIO(int listen_length);
    ~audioIO() = default;

    bool listen();
    bool pauseListen();
private:
    int recordLen = 0;
    int sampleRate = 0;

    atomic_bool running{};
};


#endif //PERSONALASSISTANT_AUDIOIO_H
