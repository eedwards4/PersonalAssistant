// Mic Listener
// Created by Ethan Edwards on 8/2/2023.
//

#ifndef PERSONALASSISTANT_AUDIOIO_H
#define PERSONALASSISTANT_AUDIOIO_H

#include <SDL_audio.h>
#include <iostream>
#include <atomic>
#include <vector>
#include <string>
#include <SDL.h>

using namespace std;

struct params{
    int sample_rate = 0;
    int sample_request = 1024;

};

class audioIO { // I'm in your walls
public:
    // Construction
    audioIO(int listen_length);
    ~audioIO();
    void SDLCallback(uint8_t* stream, int len);

    bool startListen(int sample_rate);
    bool pauseListen();
private:
    params p;
    SDL_AudioDeviceID mic = 0;
    int recordLen = 0;
    int sampleRate = 0;

    vector<float> audio;

    atomic_bool running{};
};


#endif //PERSONALASSISTANT_AUDIOIO_H
