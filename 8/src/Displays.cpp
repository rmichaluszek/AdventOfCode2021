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
        std::string delimiter = " |";
        std::string output = data[i].substr(data[i].find(delimiter)+delimiter.length()-1, data[i].length());

        std::cout <<  output << std::endl;
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

