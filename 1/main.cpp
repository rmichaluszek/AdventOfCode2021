#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<string> getData() {
// using container because of easier resizing, and i want to allow dynamic number of lines allowed

    vector<string> data;
    // for this one i could use just int, but I'll reuse this chunk of code in the next puzzles

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
    // run the method for retrieving from user multiline data input

    int increaseCounter = 0;
    int increaseSumCounter = 0;
    int previousSum = 0;
    // we only care about increases so we don't need to count decreased aswell

    for (size_t i = 0; i != data.size(); ++i) {
        // using index based for loop, because probably later on i will need indexes to do some operations on these values
        cout << data[i];

        if (i == 0) {
            // no previous data, unknown if depth increased or decreased
             cout << " (N/A - no previous measurment)" << endl;
        } else {
            if (stoi(data[i-1]) < stoi(data[i])) {
                cout << " (increased)" << endl;
                increaseCounter++;
            } else if (stoi(data[i-1]) > stoi(data[i])) {
                cout << " (decreased)" << endl;
            } else {
                cout << " (no change)" << endl;
                // just in case, because that can of course happen
            }
        }

        // part 2 calculations
        if(i+2 < data.size()) {
            // check  if we can do a sum of 3 numbers
            int sum = stoi(data[i]) + stoi(data[i+1]) + stoi(data[i+2]);
            if(i > 0) { // if this is less, then we have no previous sum of 3 numbers
                if(sum >previousSum) {
                    increaseSumCounter++;
                }
            }
            previousSum = sum;

        }
    }

    cout << "Part 1: " << increaseCounter << endl;
    // and print the result of part 1


    cout << "Part 2: " << increaseSumCounter << endl;
    // print the part 2 result


    cin;
    // waits for any key to close the program, just to see results

    return 0;
}
