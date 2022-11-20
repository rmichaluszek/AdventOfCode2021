#include <bits/stdc++.h>
#include <iostream>

#include "DataLoader.h"
#include "Lines.h"
#include "Line.h"

int main() {

    DataLoader dataLoader;
    std::vector<std::string> data = dataLoader.GetData();

    Lines lines;
    lines.ParseData(data);


    system("pause");
    // waits for any key to close the program, just to see results

    return 0;
}
