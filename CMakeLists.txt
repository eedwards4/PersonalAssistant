cmake_minimum_required(VERSION 3.26)
project(PersonalAssistant)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(SDL2_PATH "SDL2-2.28.1\\x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(PersonalAssistant STT_TESTING.cpp
        modules/core/commandHandler.h
        modules/core/commandHandler.cpp
        modules/core/STT.h
        modules/core/STT.cpp
        modules/core/audioIO.h
        modules/core/audioIO.cpp
        modules/core/whisper/ggml.h
        modules/core/whisper/ggml.c
        modules/core/whisper/whisper.h
        modules/core/whisper/whisper.cpp
)

target_link_libraries(PersonalAssistant ${SDL2_LIBRARY})
