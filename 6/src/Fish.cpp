#include "Fish.h"
#include <iostream>

Fish::Fish() {
}

Fish::~Fish() {
}

void Fish::ParseData(std::vector<std::string> data) {

    std::stringstream initialFishStream(data[0]);

    while(initialFishStream.good()) {

        // split values by comma
        std::string str;
        getline(initialFishStream,str,',');
        int daysLeft = std::stoi(str.c_str());
        this->fishList[daysLeft]++;
    }
}

void Fish::SimulateDay() {

    long long firstElementValue = this->fishList[0];
    for(int i=0; i<8; i++) {
        // skipping the last elements because it will be overwritten by first
        this->fishList[i] = this->fishList[i+1];
    }
    this->fishList[8] = firstElementValue;
    this->fishList[6] += firstElementValue;
}

long long Fish::GetFishCount() {
    long long result = 0;
    for(int i=0; i<8; i++) {
        result += this->fishList[i];
    }
    return result;
}
