#include <bits/stdc++.h>
#include <iostream>

#include "DataLoader.h"
#include "Displays.h"

int main() {

    DataLoader dataLoader;
    std::vector<std::string> data = dataLoader.GetData();

    Displays displays;
    displays.ParseData(data);

    std::cout << "There are " << displays.GetUniqueNumbersAmount() << " unique numbers" << std::endl;

    system("pause");
    // waits for any key to close the program, just to see results

    return 0;
}
