//
// Created by Ethan Edwards on 8/2/2023.
//

#ifndef PERSONALASSISTANT_COMMANDHANDLER_H
#define PERSONALASSISTANT_COMMANDHANDLER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct params{
    string notes_location = "notes.txt";
    string reminders_location = "reminders.txt";
};

class reminder{
public:
    string reminder_message;
    time_t reminder_time;
};

class commandHandler {
public:
    // Vars
    vector<string> commands{ // All active commands
        "exit",
        "time",
        "reminder",
        "note",
        "interface",
        "system"
    };

    // Construction
    commandHandler() = default;
    ~commandHandler() = default;
    // Parser
    string parse(string input);
    // Save/load commands
    void saveData();
    void loadData();

private:
    // Vars
    params params;
    vector<reminder> reminders;
    vector<string> notes;
    // Internal modules
    // Commands for Time [master command: time]
    string checkTime(); // Actual command: check

    // Commands for Reminders [master command: reminder]
    string addReminder(); // Actual command: add
    string removeReminder(); // Actual command: remove
    string checkReminders(); // Actual command: check

    // Commands for Notes [master command: note]
    string addNote(); // Actual command: add
    string removeNote(); // Actual command: remove
    string checkNotes(); // Actual command: check

    // Commands for UI [master command: interface]
    string uiOpen(string message); // Actual command: open
    string uiClose(string message); // Actual command: close

    // Commands for System [master command: system]
    string sysOpen(string message); // Actual command: open
    string sysClose(string message); // Actual command: close

};


#endif //PERSONALASSISTANT_COMMANDHANDLER_H
