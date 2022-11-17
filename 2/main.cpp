#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> getData() {
// using container because of easier resizing, and i want to allow dynamic number of lines allowed

    vector<string> data;

    bool inputEnabled = true;

    while(inputEnabled) {

        string l = "";

        getline(cin,l);

        if(l.length()<= 0)
            inputEnabled = false;
            // if the input is empty, then stop the user input
        else
            data.push_back(l);
            // if it's not empty, add the value to the coontainer
    }

    return data;
}


// commands as enums to easy use them in switch casee
enum Commands {
    Forward,
    Down,
    Up
};
Commands resolveCommands(string input);

// this one will match the command string with it's enum ( for the switch use )
Commands resolveCommands(string input) {
    if( input == "forward" ) return Forward;
    if( input == "down" ) return Down;
    if( input == "up" ) return Up;
    return Forward; // should never happen in this scenario of puzzle, but there needs to be a default return value
}

int main()
{
    vector<string> data = getData();

    int horizontalPos = 0;
    int depth = 0;

    for (size_t i = 0; i != data.size(); ++i) {

        string line = data[i];
        string splitCharacter = " ";
        // determine by which character the line should be divided into command and value

        string command = line.substr(0, line.find(splitCharacter));
        // first part of the line
        string valueStr = line.substr(line.find(splitCharacter), (line.length() - line.find(splitCharacter)));
        int value = stoi(valueStr);
        // second part of the line


        // just execute the commands and change values depending on what's in input
        switch(resolveCommands(command)) {
            case Forward:
                horizontalPos += value;
                break;
            case Down:
                depth += value;
                break;
            case Up:
                depth -= value;
                break;
            // should be default and other types of validation, but for the puzzles, I'm doing only what's needed to run the puzzle
        }
    }

    // print the depth and the horizontal position
    cout << "Horizontal: " << horizontalPos << " / Depth: " << depth << endl;

    // and the multiplication of these
    cout << horizontalPos*depth << endl;

    cin;
    // waits for any key to close the program, just to see results

    return 0;
}
