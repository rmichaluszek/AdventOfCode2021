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
            data.push_back("Empty");
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

    void DisplayValues() {
        for(int i=0; i< 5; i++) {
            for(int j=0; j< 5; j++) {
                cout << values[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    vector<string> data = getData();
    vector<int> bingoValues;
    vector<BingoBoard> bingoBoards;

    int bingoBoardStartingLine = 2; // first one starts at third line

    for (size_t i = 0; i != data.size(); ++i) {
        // first line are values, and later on are bingo boards every "/n" line
        if (i == 0) {
            stringstream valuesStream(data[0]);

            while(valuesStream.good()) {

                // split values by comma
                string str;
                getline(valuesStream,str,',');
                int value = stoi(str.c_str());
                bingoValues.push_back(value);
            }
        } else {
            if( i == bingoBoardStartingLine ) {

                BingoBoard newBingoBoard;
                for(int y = 0; y < 5; y++) {

                    vector<int> values;
                    // split the line into 5 integer values

                    regex double_spaces("[ ]{2,}");
                    data[bingoBoardStartingLine+y] = regex_replace(data[bingoBoardStartingLine+y], double_spaces, " ");
                    // sometimes there are two spaces between numbers so we skip empty symbol

                    if (data[bingoBoardStartingLine+y][0] == ' ') {
                        data[bingoBoardStartingLine+y].erase(data[bingoBoardStartingLine+y].begin());
                    }
                    // and sometimes the whitespace is at the begging, so get rid of it aswell

                    stringstream valuesStream(data[bingoBoardStartingLine+y]);

                    while(valuesStream.good()) {
                        // split values by space
                        string str;
                        getline(valuesStream,str,' ');
                        int value = stoi(str);
                        values.push_back(value);
                    }

                    for(int j = 0; j<5; j++) {
                        newBingoBoard.values[y][j] = values[j];
                    }
                }

                bingoBoards.push_back(newBingoBoard);
                // check if there are bingo boards left
                if(bingoBoardStartingLine+5 < data.size())
                {
                    bingoBoardStartingLine+= 6;
                }
            }
        }

    }
    // data is split into valus and boards, time to play bingo


    cin;
    // waits for any key to close the program, just to see results

    return 0;
}
