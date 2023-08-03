// Wrapper for the whisper STT library
// Created by Ethan Edwards on 8/2/2023.
//

#ifndef PERSONALASSISTANT_STT_H
#define PERSONALASSISTANT_STT_H

#include <string>

using namespace std;

class STT {
public:
    STT();
    ~STT() = default;
    string parseAudio();
};


#endif //PERSONALASSISTANT_STT_H
