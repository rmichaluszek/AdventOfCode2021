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
    }
}

void Fish::SimulateDay() {

    for(size_t i=0; i!=this->fishList.size();i++) {

        this->fishList[i]--;

        if(this->fishList[i] <= -1) {
            // spawn new fish, but add it another 1 day because it will be decremented today,
            // another way would be to spawn the new fish at the start of vector
            this->fishList.push_back(9); // new fish needs 8 days to spawn another fish
            this->fishList[i] = 6; // and this one needs 6 days to spawn another
        }
    }
}
