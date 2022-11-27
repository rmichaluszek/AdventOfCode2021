#include <bits/stdc++.h>
#include <iostream>

#include "DataLoader.h"
#include "Crabs.h"

int main() {

    DataLoader dataLoader;
    std::vector<std::string> data = dataLoader.GetData();

    Crabs crabs;
    crabs.ParseData(data);

    std::cout << "Part 1 result is: " << crabs.SolvePart1() << std::endl;
    std::cout << "Part 2 result is: " << crabs.SolvePart2() << std::endl;

    system("pause");
    // waits for any key to close the program, just to see results

    return 0;
}
