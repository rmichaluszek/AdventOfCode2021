#include <bits/stdc++.h>
#include <iostream>

#include "DataLoader.h"
#include "Crabs.h"

int main() {

    DataLoader dataLoader;
    std::vector<std::string> data = dataLoader.GetData();

    Crabs crabs;
    crabs.ParseData(data);

    std::cout << "Result is: " << crabs.Solve() << std::endl;

    system("pause");
    // waits for any key to close the program, just to see results

    return 0;
}
