// Fai Driver
// Created by Ethan Edwards on 8/2/2023.
// All rights reserved I guess

/*
 * Main driver for Fai (pronounced fay) personal assistant project
 */

#include <iostream>
#include <string>

#include "modules/core/commandHandler.h"

using namespace std;

string lower(string input);
string getFirst(string input);

int main() {
    cout << "Starting Fai..." << endl;
    string input, output, command;
    bool running = true, gotCommand = false;

    // Init modules
    cout << "Initializing core modules..." << endl;
    commandHandler stem; stem.loadData();
    // init ears [audioIO]
    // init frontalLobe [STT]
    // init mouth [TTS]
    // init cerebrum [LLM]
    cout << "Core module initialization complete..." << endl;
    cout << "Initializing external modules..." << endl;
    // init external modules
    cout << "External module initialization complete..." << endl;
    cout << "Module initialization complete" << endl;

    cout << "Starting main program runtime. 'fay exit' to exit." << endl;
    while(running){
        // Record audio
        // Pass to STT
        cout << "Enter a command: ";
        getline(cin, input);
        // Make string lowercase
        lower(input);
        // Check against wakeword
        if (input.find("fay") != string::npos){
            // Crop string to command
            input = input.substr(input.find("fay") + 4, input.length() - 1);
            // Get first word
            command = getFirst(input);
            // Check for command
            for (const string& i : stem.commands){
                if (command == i){
                    gotCommand = true;
                    break;
                }
            }
            if (gotCommand){
                if (command == "exit"){ // Hardcoded exit command
                    output = "Goodbye!";
                    running = false;
                }
                else{
                    output = stem.parse(input);
                }
            }
            else {
                output = "LLM RESPONSE PLACEHOLDER";
            }
            if (!output.empty()){
                cout << output << endl;
            }
            output = ""; input = ""; command = "";
            gotCommand = false;
        }
    }
    stem.saveData();
    return 0;
}

string getFirst(string input){
    string output;
    output = input.substr(0, input.find(' '));
    return output;
}

string lower(string input){
    for (char& i : input){
        i = tolower(i);
    }
    return input;
}
