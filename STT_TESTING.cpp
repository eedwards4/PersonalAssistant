//
// Created by evane on 8/2/2023.
//

#include "/modules/core/whisper/whisper.h"


#include <cassert>
#include <cstdio>
#include <fstream>
#include <regex>
#include <string>
#include <thread>
#include <vector>
#include <regex>

struct whisper_params {
    int32_t n_threads  = std::min(4, (int32_t) std::thread::hardware_concurrency());
    int32_t voice_ms   = 10000;
    int32_t capture_id = -1;
    int32_t max_tokens = 32;
    int32_t audio_ctx  = 0;

    float vad_thold    = 0.6f;
    float freq_thold   = 100.0f;

    bool speed_up      = false;
    bool translate     = false;
    bool print_special = false;
    bool print_energy  = false;
    bool no_timestamps = true;

    std::string person    = "Santa";
    std::string language  = "en";
    std::string model_wsp = "modules/core/whisper/ggml-base.en.bin";
    std::string model_gpt = "models/ggml-gpt-2-117M.bin";
    std::string speak     = "./examples/talk/speak";
    std::string fname_out;
};

int main(){
    // Init whisper
    whisper_params params;
    struct whisper_context * ctx_wsp = whisper_init_from_file(params.model_wsp.c_str());

    // Init audio



    return 0;
}
