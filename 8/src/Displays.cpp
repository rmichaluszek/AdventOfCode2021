#include "Displays.h"

Displays::Displays(){
}

Displays::~Displays() {
}

void Displays::ParseData(std::vector<std::string> data) {

    for(size_t i = 0; i != data.size();  i++ ) {
        std::stringstream initialData(data[i]);

        // output is on the right side of |
        // acedgfb cdfbe gcdfa fbcad dab cefabd cdfgeb eafb cagedb ab | cdfeb fcadb cdfeb cdbaf

        // get data after by ' |'
        std::string delimiter = " | ";
        std::string input = data[i].substr(0,data[i].find(delimiter)+delimiter.length()-3);
        std::string output = data[i].substr(data[i].find(delimiter)+delimiter.length(), data[i].length());

        this->inputs.push_back(input);
        this->outputs.push_back(output);
    }
}

int Displays::GetUniqueNumbersAmount() {

    int result = 0;

    for(size_t i = 0; i!=this->outputs.size();i++) {
        // unique numbers are made with 2,3,4 or 7 segments

        std::stringstream initialData(this->outputs[i]);

        while(initialData.good()) {
            // split values by space
            std::string number;
            getline(initialData,number,' ');

            bool isUnique = false;

            switch(number.length()) {
                case 2:
                    isUnique = true;
                    break;
                case 3:
                    isUnique = true;
                    break;
                case 4:
                    isUnique = true;
                    break;
                case 7:
                    isUnique = true;
                    break;

            }
            if(isUnique) {
                result++;
            }

        }
    }
    return result;
}

long long Displays::GetOutputValues() {

    long long result = 0;

    for(size_t i = 0; i!=this->outputs.size();i++) {

        std::stringstream initialDataInputs(this->inputs[i]);
        std::stringstream initialDataOutputs(this->outputs[i]);
        std::stringstream initialDataOutputsForResults(this->outputs[i]);


        std::string numbersDecoded[10] = {""};
        std::vector<std::string> numbersYetToDecode;


        while(initialDataInputs.good()) {
            std::string number;
            getline(initialDataInputs,number,' ');

            // first we mark all the 1, 4, 7 and 8 numbers because they are unique

            switch(number.length()) {
                case 2: // 1
                    numbersDecoded[1] = SortInputWires(number);
                    break;
                case 3: // 7
                    numbersDecoded[7] = SortInputWires(number);
                    break;
                case 4: // 4
                    numbersDecoded[4] = SortInputWires(number);
                    break;
                case 7: // 8
                    numbersDecoded[8] = SortInputWires(number);
                    break;
                default:
                    numbersYetToDecode.push_back(SortInputWires(number));
                    break;

            }

        }

        while(initialDataOutputs.good()) {
            std::string number;
            getline(initialDataOutputs,number,' ');

            // first we mark all the 1, 4, 7 and 8 numbers because they are unique

            switch(number.length()) {
                case 2: // 1
                    numbersDecoded[1] = SortInputWires(number);
                    break;
                case 3: // 7
                    numbersDecoded[7] = SortInputWires(number);
                    break;
                case 4: // 4
                    numbersDecoded[4] = SortInputWires(number);
                    break;
                case 7: // 8
                    numbersDecoded[8] = SortInputWires(number);
                    break;
                default:
                    numbersYetToDecode.push_back(SortInputWires(number));
                    break;
            }

        }
        // now when we have all the unique numbers, we should be able to determine other numbers by trying to intersect them

        while(numbersYetToDecode.size()!=0) {
            for(size_t x=0; x<numbersYetToDecode.size();x++) {
                bool foundNumber = true;

                if(numbersYetToDecode[x].length()==6) {
                    if(IsNumberInAnotherNumber(numbersDecoded[4],numbersYetToDecode[x])) {
                        numbersDecoded[9] = numbersYetToDecode[x];
                        numbersYetToDecode.erase(numbersYetToDecode.begin()+x);
                        break;
                    } else if(IsNumberInAnotherNumber(numbersDecoded[7],numbersYetToDecode[x])) {
                        numbersDecoded[0] = numbersYetToDecode[x];
                        numbersYetToDecode.erase(numbersYetToDecode.begin()+x);
                        break;
                    } else {
                        // it has to be 6
                        numbersDecoded[6] = numbersYetToDecode[x];
                        numbersYetToDecode.erase(numbersYetToDecode.begin()+x);
                        break;
                    }
                } else {
                    if(numbersYetToDecode[x].length()==5) {

                        if(IsNumberInAnotherNumber(numbersDecoded[1],numbersYetToDecode[x])) {
                            numbersDecoded[3] = numbersYetToDecode[x];
                            numbersYetToDecode.erase(numbersYetToDecode.begin()+x);
                            break;
                        }
                        if(numbersDecoded[6] != "") {
                            if(IsNumberInAnotherNumber(numbersYetToDecode[x],numbersDecoded[6])) {

                                numbersDecoded[5] = numbersYetToDecode[x];
                                numbersYetToDecode.erase(numbersYetToDecode.begin()+x);
                                break;
                            } else {
                                // it has to be 2
                                numbersDecoded[2] = numbersYetToDecode[x];
                                numbersYetToDecode.erase(numbersYetToDecode.begin()+x);
                                break;
                            }
                        }
                    }
                }
            }
        }
        // now we should have all the numbers decoded, let's sum the values

        std::string outputNumber = "";

        while(initialDataOutputsForResults.good()) {
            std::string number;
            getline(initialDataOutputsForResults,number,' ');

            std::string sortedWires = SortInputWires(number);

            for(int i=0; i<sizeof(numbersDecoded) / sizeof(numbersDecoded[0]);i++) {
                if(sortedWires==numbersDecoded[i]){
                    outputNumber+= std::to_string(i);

                }
            }
        }
        result += stoi(outputNumber);

    }
    return result;
}

bool Displays::IsNumberInAnotherNumber(std::string a,std::string b) {
    bool result = false;
    for(int i=0; i< a.length();i++) {
        if(b.find(a[i])!=std::string::npos) {
            result = true;
        } else {
            result = false;
            break;
        }
    }

    return result;
}

// this is for sorting the wires alphabetically, because sometimes 7 is stored as cbg and gcb
std::string Displays::SortInputWires(std::string data) {
    sort(data.begin(), data.end());
    return data;
}

