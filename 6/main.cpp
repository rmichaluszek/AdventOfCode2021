#include <bits/stdc++.h>
#include <iostream>

#include "DataLoader.h"
#include "Fish.h"

int main() {

    DataLoader dataLoader;
    std::vector<std::string> data = dataLoader.GetData();

    Fish fish;
    fish.ParseData(data);

    for(int i=0; i< 80; i++) {
        fish.SimulateDay();
    }

    std::cout << "After 80 days there are " << fish.fishList.size() << " fish." << std::endl;

    system("pause");
    // waits for any key to close the program, just to see results

    return 0;
}
