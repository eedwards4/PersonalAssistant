<h1 align="center">PersonalAssistant</h1>
PersonalAssistant is a small project with the goal of creating a multiplatform personal assistant (referred to as Fay) for daily tasks (similar to siri or alexa, but open source).

<h2>Building/Running</h2>
PersonalAssistant requires Whisper.cpp to run. However, due to the size of certain dependancies the entire project cannot be hosted on github.
In order to build you <b>MUST</b> do the following:

1. Download `SDL2-devel-2.28.1-mingw.zip` from [the SDL2 release page](https://github.com/libsdl-org/SDL/releases/tag/release-2.28.2).
2. Unzip the folder into the root directory of PersonalAssistant (`/PersonalAssistant`).
3. Clone the [Whisper.cpp](https://github.com/ggerganov/whisper.cpp/tree/master) repository.
4. Follow the Sample Download guide from [Whisper.cpp](https://github.com/ggerganov/whisper.cpp/blob/master/models/README.md) in order to obtain a copy of `ggml-base.en.bin`.
5. Copy or move `ggml-base.en.bin` to `/PersonalAssistant/modules/core/whisper`
6. Build the project with cmake (trust me, the g++ command is unpleasant at best).
7. Profit?

<h2>Roadmap</h2>
<h3>Version 1.0</h3>

- [x] Basic command structure

- [ ] Voice recognition (Using Whisper.cpp)
    
- [ ] Text to speech (Using Piper)
      
<h3>Version 1.5</h3>

- [ ] Builtin LLM (Using LocalAI)

- [ ] External command structure (Other programs/APIs)
      
- [ ] Basic GUI

<h2>Credits</h2>

- [Whisper.cpp](https://github.com/ggerganov/whisper.cpp)

- [SDL](https://www.libsdl.org/)

