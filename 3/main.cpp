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

    vector<string> oxygenData = data;
    vector<string> co2Data = data;

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
    cout << "Part 1: " << gammaPower*epsilonPower << endl;

    // part 2

    // oxygen
    for (short j = 0; j < bitsLength; j++) {
        short ones = 0;
        short zeros = 0;
        for(size_t i=0; i!=oxygenData.size();i++) {
            char *bit = new char(oxygenData[i][j]);
            if(*bit=='0') zeros++;
            else if(*bit=='1') ones++;

            delete bit;
        }

        char bitToKeep = (ones>=zeros)? '1' : '0';

        for(size_t i=0; i<oxygenData.size();i++) {
            if(i<oxygenData.size()) {
                char bit = oxygenData[i][j];
                if(bit!=bitToKeep) {
                    oxygenData.erase(oxygenData.begin() + i);
                    i--;
                }
            }
        }

        if(oxygenData.size() == 1) {
            break;
        }
    }
    // carbon
    for (short j = 0; j < bitsLength; j++) {
        short ones = 0;
        short zeros = 0;
        for(size_t i=0; i!=co2Data.size();i++) {
            char *bit = new char(co2Data[i][j]);
            if(*bit=='0') zeros++;
            else if(*bit=='1') ones++;

            delete bit;
        }

        char bitToKeep = (zeros<=ones)? '0' : '1';

        for(size_t i=0; i<co2Data.size();i++) {
            if(i<co2Data.size()) {
                char bit = co2Data[i][j];
                if(bit!=bitToKeep) {
                    co2Data.erase(co2Data.begin() + i);
                    i--;
                }
            }
        }

        if(co2Data.size() == 1) {
            break;
        }
    }

    cout << "Part 2: " << stoi(oxygenData[0],0,2)*stoi(co2Data[0],0,2) << endl;

    cin;
    // waits for any key to close the program, just to see results

    return 0;
}
