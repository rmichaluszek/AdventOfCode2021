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

    // no number is crossing the value of 1000, so that's how big diagram will be
    short diagram[1000][1000];

    for(short y = 0; y < 1000;y++) {
        for(short x = 0; x < 1000;x++) {
            diagram[x][y] = 0; // 0 lines cover that point for now
        }
    }

    for(Line l : lines.lines) {
        std::vector<std::pair<short,short>> points = l.getCoveredPoints();
        for(size_t i=0;i<points.size();i++) {
            diagram[ std::get<0>(points[i]) ][ std::get<1>(points[i])  ]++;
        }
    }



    // check how many points are overlapping more than two times
    short moreThanTwoOverLapsCounter = 0;
    for(int i = 0; i < 1000;i++) {
        for(int j = 0; j < 1000;j++) {
            if(diagram[j][i] >= 2) {
                moreThanTwoOverLapsCounter++;
            }
        }
    }

    std::cout << "The result is: " << moreThanTwoOverLapsCounter << std::endl;


    system("pause");
    // waits for any key to close the program, just to see results

    return 0;
}
