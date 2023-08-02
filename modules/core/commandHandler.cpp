//
// Created by Ethan Edwards on 8/2/2023.
//

#include "commandHandler.h"

string getAndRemoveFirst(string& input){
    string output;
    output = input.substr(0, input.find(' '));
    input.erase(0, input.find(' ') + 1);
    return output;
}

string commandHandler::parse(string input) {
    string output;
    string command = getAndRemoveFirst(input);
    // Parse command. Internal modules first, then offline external, then online external
    if (command == "time"){
        command = getAndRemoveFirst(input);
        if (command == "check"){
            output = checkTime();
        }
    } else if (command == "reminder"){
        command = getAndRemoveFirst(input);
        if (command == "add"){
            output = addReminder();
        } else if (command == "remove"){
            output = removeReminder();
        } else if (command == "check"){
            output = checkReminders();
        }
    } else if (command == "note"){
        command = getAndRemoveFirst(input);
        if (command == "add"){
            output = addNote();
        } else if (command == "remove"){
            output = removeNote();
        } else if (command == "check"){
            output = checkNotes();
        }
    } else if (command == "interface"){
        command = getAndRemoveFirst(input);
        if (command == "open"){
            output = uiOpen(input);
        } else if (command == "close"){
            output = uiClose(input);
        }
    } else if (command == "system"){
        command = getAndRemoveFirst(input);
        if (command == "open"){
            output = sysOpen(input);
        } else if (command == "close"){
            output = sysClose(input);
        }
    }
    else{
        output = "ERROR: COMMAND NOT FOUND"; // Should NEVER see this
    }
    return output;
}

void commandHandler::saveData() { // Save all data to files
    ofstream reminderFile; reminderFile.open(params.reminders_location);
    ofstream noteFile; noteFile.open(params.notes_location);

    if (noteFile.is_open()){
        for (string i : notes){
            noteFile << i << endl;
        }
        noteFile.close();
    } else{
        cout << "ERROR: FAILURE TO OPEN CRITICAL FILE " << params.notes_location << endl;
    }

    if (reminderFile.is_open()){
        for (reminder i : reminders){
            reminderFile << i.reminder_message << endl;
        }
        reminderFile.close();
    } else{
        cout << "ERROR: FAILURE TO OPEN CRITICAL FILE " << params.reminders_location << endl;
    }
}

void commandHandler::loadData() { // Load all data from files
    ifstream reminderFile(params.reminders_location);
    ifstream noteFile(params.notes_location);
    string line;
    if (noteFile.is_open()){
        while (getline(noteFile, line)){
            notes.push_back(line);
        }
        noteFile.close();
    } else{
        cout << "ERROR: FAILURE TO OPEN CRITICAL FILE " << params.notes_location << endl;
    }

    if (reminderFile.is_open()){
        while (getline(reminderFile, line)){
            reminder temp;
            temp.reminder_message = line;
            reminders.push_back(temp);
        }
        reminderFile.close();
    } else{
        cout << "ERROR: FAILURE TO OPEN CRITICAL FILE " << params.reminders_location << endl;
    }
}

// Commands for time
string commandHandler::checkTime() { // Get the current date and time
    stringstream ss;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    ss << "The current date and time is: " << asctime(ltm);
    return ss.str();
}

// Commands for reminders
string commandHandler::addReminder() { // Add a reminder to the list of reminders
    reminder temp;
    cout << "What would you like the reminder to say?" << endl;
    getline(cin, temp.reminder_message);
    // cout << "When would you like the reminder to be displayed?" << endl;
    // cin >> temp.reminder_time;
    reminders.push_back(temp);

    stringstream ss;
    ss << "Added reminder: " << temp.reminder_message << ".";
    return ss.str();
}

string commandHandler::removeReminder() { // Remove a reminder from the list of reminders
    string response, temp;

    cout << "Currently there are " << reminders.size() << " reminders. Please indicate which reminder you would like to remove." << endl;
    for (int i = 0; i < reminders.size(); i++){
        cout << i << ": " << reminders[i].reminder_message << endl;
        cout << "Remove this reminder? ";
        cin >> response;
        if (response == "yes"){
            temp = reminders[i].reminder_message;
            reminders.erase(reminders.begin() + i);
            break;
        }
    }
    cout << "Would you like to remove another reminder? ";
    cin >> response;
    if (response == "yes" && !reminders.empty()){
        removeReminder();
    }

    stringstream ss;
    ss << "Removed reminder: " << temp << ".";
    return ss.str();
}

string commandHandler::checkReminders() { // Check the list of reminders
    cout << "Currently there are " << reminders.size() << " reminders." << endl;
    for (reminder i : reminders){
        cout << i.reminder_message << endl;
    }

    stringstream ss;
    ss << "End of reminders.";
    return ss.str();
}

// Commands for notes
string commandHandler::addNote() { // Add a note to the list of notes
    string temp;
    cout << "What would you like the note to say?" << endl;
    getline(cin, temp);
    notes.push_back(temp);

    stringstream ss;
    ss << "Added note: " << temp << ".";
    return ss.str();
}

string commandHandler::removeNote() { // Remove a note from the list of notes
    string response, temp;

    cout << "There are currently " << notes.size() << " notes. Please indicate which note you would like to remove." << endl;
    for (int i = 0; i < notes.size(); i++){
        cout << i << ": " << notes[i] << endl;
        cout << "Remove this note? ";
        cin >> response;
        if (response == "yes"){
            temp = notes[i];
            notes.erase(notes.begin() + i);
            break;
        }
    }
    cout << "Would you like to remove another note? ";
    cin >> response;
    if (response == "yes" && notes.size() > 0){
        removeNote();
    }

    stringstream ss;
    ss << "Removed note: " << temp << ".";
    return ss.str();
}

string commandHandler::checkNotes() { // Check the list of notes
    cout << "There are currently " << notes.size() << " notes." << endl;
    for (string i : notes){
        cout << i << endl;
    }

    stringstream ss;
    ss << "Checked notes";
    return ss.str();
}

// Commands for interface
string commandHandler::uiOpen(std::string input) { // Open a program, and store its PID in a list of controlled processes
    stringstream ss;
    ss << "Opened ui";
    return ss.str();
}

string commandHandler::uiClose(std::string input) { // Check list of controlled processes, and kill the one with the given name
    stringstream ss;
    ss << "Closed ui";
    return ss.str();
}

// Commands for system
string commandHandler::sysOpen(std::string input) { // Open a program, and store its PID in a list of controlled processes
    stringstream ss;
    ss << "Opened " << input << ".";
    return ss.str();
}

string commandHandler::sysClose(std::string input) { // Check list of controlled processes, and kill the one with the given name
    stringstream ss;
    ss << "Closed " << input << ".";
    return ss.str();
}
