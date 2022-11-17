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

int main()
{
    vector<string> data = getData();

    for (size_t i = 0; i != data.size(); ++i) {

        string line = data[i];
        string splitCharacter = " ";
        // determine by which character the line should be divided into command and value

        string command = line.substr(0, line.find(splitCharacter));
        // first part of the line
        string valueStr = line.substr(line.find(splitCharacter), (line.length() - line.find(splitCharacter)));
        int value = stoi(valueStr);
        // second part of the line

        cout << command << endl;
        cout << value << endl;
    }
    cin;
    // waits for any key to close the program, just to see results

    return 0;
}
