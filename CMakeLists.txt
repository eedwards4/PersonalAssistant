cmake_minimum_required(VERSION 3.26)
project(PersonalAssistant)

set(CMAKE_CXX_STANDARD 17)

add_executable(PersonalAssistant main.cpp
        modules/core/commandHandler.h
        modules/core/commandHandler.cpp
        modules/core/whisper/ggml.h
        modules/core/whisper/ggml.c
        modules/core/whisper/whisper.h
        modules/core/whisper/whisper.cpp
)
