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
        short daysLeft = std::stoi(str.c_str());
        this->fishList.push_back(daysLeft);

        std::cout << daysLeft << std::endl;
    }
}

int Fish::SimulateDay() {

    return this->fishList.size();
}
