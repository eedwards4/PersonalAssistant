// Mic Listener
// Created by Ethan Edwards on 8/2/2023.
//

#include "audioIO.h"

audioIO::audioIO(int listen_length) {
    recordLen = listen_length;
    running = false;
}

audioIO::~audioIO() {
    if(mic){
        SDL_CloseAudioDevice(mic);
    }
    running = false;
}

bool audioIO::startListen(int sample_rate) {
    SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO);
    int mics = SDL_GetNumAudioDevices(SDL_TRUE);
    char input;

    if (SDL_Init(SDL_INIT_AUDIO) < 0){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL FAILURE: %s\n", SDL_GetError());
        return false;
    }

    SDL_SetHintWithPriority(SDL_HINT_AUDIO_RESAMPLING_MODE, "medium", SDL_HINT_OVERRIDE);

    // Init microphone

    SDL_AudioSpec mic_requested;
    SDL_AudioSpec mic_obtained;

    SDL_zero(mic_requested);
    SDL_zero(mic_obtained);

    mic_requested.freq = p.sample_rate;
    mic_requested.format = AUDIO_F32;
    mic_requested.channels = 1;
    mic_requested.samples = p.sample_request;

    cout << "Found " << mics << " microphones. Please select:" << endl;
    for (int i = 0; i < mics;){
        cout << i << ":" << SDL_GetAudioDeviceName(i, SDL_TRUE) << endl;
        cout << "Select? (y/n): ";
        cin >> input;
        if (input == 'y'){
            cout << "Initializing microphone..." << endl;
            mic = SDL_OpenAudioDevice(SDL_GetAudioDeviceName(i, SDL_TRUE), SDL_TRUE, &mic_requested, &mic_obtained, 0);
            if (!mic){
                cout << "MIC INIT FAILURE: " << SDL_GetError() << endl;
                return false;
            }
            cout << "Microphone initialized." << endl;
            break;
        } else if (input == 'n'){
            i++;
        } else {
            cout << "Invalid input. Please try again." << endl;
            i--;
        }
    }

    sampleRate = mic_obtained.freq;
    audio.resize((sampleRate*recordLen)/1000);

    return true;
}

void audioIO::SDLCallback(uint8_t *stream, int len) {
    if (!running){
        return;
    }


}
