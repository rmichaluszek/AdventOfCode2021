#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<string> getData() {
// using container because of easier resizing, and i want to allow dynamic number of lines allowed

    vector<string> data;

    bool inputEnabled = true;

    // this time the data can have empty line, so input ends when empty line is entered 2 times in a row
    int entersPressed = 0;

    while(inputEnabled) {

        string l = "";

        getline(cin,l);

        if(l.length()<= 0)
            entersPressed++;
        else {
           entersPressed = 0;
        }
        // if the input is empty, then stop the user input
        if (entersPressed==0)
            data.push_back(l);
        else if (entersPressed == 1)
            data.push_back("\n");
        else inputEnabled = false;
            // if it's not empty, add the value to the container
    }

    return data;
}


class BingoBoard {
  public:

    // 2d arrays with numbers of the board
    int values[5][5] = {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
    };

    // 2d array of marked values (true/false)
    bool markedValues[5][5] = {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
    };

    bool CheckForBingo() {
        //
        return false;
    }
};

int main()
{
    vector<string> data = getData();

    vector<int> bingoValues;

    for (size_t i = 0; i != data.size(); ++i) {
        // first line are values, and later on are bingo boards every "/n" line

        if (i == 0) {

            stringstream valuesStream(data[0]);

            while(valuesStream.good()) {

                // split values by comma
                string str;
                getline(valuesStream,str,',');
                int value = stoi(str);
                bingoValues.push_back(value);

                cout << value << endl;
            }
        }

    }
    cin;
    // waits for any key to close the program, just to see results

    return 0;
}
