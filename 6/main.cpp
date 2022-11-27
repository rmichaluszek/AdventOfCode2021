#include <bits/stdc++.h>
#include <iostream>

#include "DataLoader.h"
#include "Fish.h"

int main() {

    DataLoader dataLoader;
    std::vector<std::string> data = dataLoader.GetData();

    Fish fish;
    fish.ParseData(data);

    long long part1Result = 0;
    long long part2Result = 0;

    for(int i=0; i< 257; i++) {
        fish.SimulateDay();
        if(i==80) {
            part1Result = fish.GetFishCount();
        } else if (i == 256) {
            part2Result = fish.GetFishCount();
        }
    }

    std::cout << "After 80 days there are " << part1Result << " fish." << std::endl;
    std::cout << "After 256 days there are " << part2Result << " fish." << std::endl;


    system("pause");
    // waits for any key to close the program, just to see results

    return 0;
}
