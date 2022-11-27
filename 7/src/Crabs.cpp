#include "Crabs.h"
#include <iostream>

Crabs::Crabs() {
}


Crabs::~Crabs() {
}

void Crabs::ParseData(std::vector<std::string> data) {

    std::stringstream initialCrabsPositions(data[0]);

    while(initialCrabsPositions.good()) {

        // split values by comma
        std::string str;
        getline(initialCrabsPositions,str,',');
        short position = std::stoi(str.c_str());
        this->crabsPositions.push_back(position);
    }

}

int Crabs::SolvePart1() {
    int bestFuelUsage = 999999;

    int minimumPosition = *std::min_element(std::begin(this->crabsPositions), std::end(this->crabsPositions));
    int maximumPosition = *std::max_element(std::begin(this->crabsPositions), std::end(this->crabsPositions));

    for(int i=minimumPosition; i!=maximumPosition;i++) {
        int fuelUsed = 0;
        for(size_t x=0; x!=this->crabsPositions.size();x++) {
            fuelUsed += abs(this->crabsPositions[x] - i);
        }
        if (fuelUsed < bestFuelUsage) {
            bestFuelUsage = fuelUsed;
        }
    }

    return bestFuelUsage;
}

int Crabs::SolvePart2() {
    int bestFuelUsage = 999999999;

    int minimumPosition = *std::min_element(std::begin(this->crabsPositions), std::end(this->crabsPositions));
    int maximumPosition = *std::max_element(std::begin(this->crabsPositions), std::end(this->crabsPositions));

    for(int i=minimumPosition; i!=maximumPosition;i++) {
        int fuelUsed = 0;
        for(size_t x=0; x!=this->crabsPositions.size();x++) {
            int thisCrabFuelUsage = 0;
            int distance = abs(this->crabsPositions[x] - i);
            for(int d = 0; d<distance;d++) {
                thisCrabFuelUsage+=d+1;
            }
            fuelUsed += thisCrabFuelUsage;
        }
        if (fuelUsed < bestFuelUsage) {
            bestFuelUsage = fuelUsed;
        }
    }

    return bestFuelUsage;
}

