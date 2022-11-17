#include <bits/stdc++.h>
#include <iostream>

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
    // run the method for retrieving from user multiline data input

    for (size_t i = 0; i != data.size(); ++i) {
        // using index based for loop, because probably later on i will need indexes to do some operations on these values
        cout << data[i] << endl;
    }

    cin;
    // waits for any key to close the program, just to see results

    return 0;
}