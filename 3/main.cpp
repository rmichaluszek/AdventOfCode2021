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

    int bitsLength = data[0].length();

    int numberOfOnes[bitsLength] = { 0 };
    int numberOfZeros[bitsLength] = { 0 };
    // later on, if the numberOfOnes[i] is greater than zeros, then the gamma rate for 'i' bit is 1, and epsilon is the opposite (0)

    for (size_t i = 0; i != data.size(); ++i) {

        string dataLine = data[i];
        for (int j = 0; j < bitsLength; j++) {
            char c = dataLine[j];

            if(c == '1') {
                numberOfOnes[j]++;
            } else {
                numberOfZeros[j]++;
            }
        }
        // count the amount of ones and zeros in each column (j) iterating trough every row (i)
    }

    string gammaBits = "";
    string epsilonBits = "";
    // check which amount is greater in each of the columns (j)
    for (int j = 0; j < bitsLength; j++) {
        if (numberOfOnes[j] > numberOfZeros[j]) {
            gammaBits += "1";
            epsilonBits += "0";
        } else {
            gammaBits += "0";
            epsilonBits += "1";
        }
    }

    // convert from binary code into decimal (int)
    int gammaPower = stoi(gammaBits, 0, 2);
    int epsilonPower = stoi(epsilonBits, 0, 2);

    // and print the result of the puzzle
    cout << gammaPower*epsilonPower << endl;
    cin;
    // waits for any key to close the program, just to see results

    return 0;
}
