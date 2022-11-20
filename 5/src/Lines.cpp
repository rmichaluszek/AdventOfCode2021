#include "Lines.h"
#include <bits/stdc++.h>

#include "Line.h"

Lines::Lines() {
}

Lines::~Lines() {
}

void Lines::ParseData(std::vector<std::string> data) {

    for(size_t i = 0; i != data.size(); i++) {
        // 0,9 -> 5,9 // data looks like this

        std::string linesDelimiter = " -> ";
        std::string lineStart = data[i].substr(0, data[i].find(linesDelimiter));
        std::string lineEnd = data[i].substr(data[i].find(linesDelimiter)+4, data[i].length());


        std::string pointsDelimiter = ",";

        std::string x1 = lineStart.substr(0, lineStart.find(pointsDelimiter));
        std::string y1 = lineStart.substr(lineStart.find(pointsDelimiter)+1, lineStart.find(pointsDelimiter)+2);

        std::string x2 = lineEnd.substr(0, lineEnd.find(pointsDelimiter));
        std::string y2 = lineEnd.substr(lineEnd.find(pointsDelimiter)+1, lineEnd.find(pointsDelimiter)+2);

        // were told to consider only horizontal and vertical line, so push only these into the stack

        if (x1==x2 || y1==y2) {
            Line newLine;
            newLine.x1 = std::stoi(x1);
            newLine.y1 = std::stoi(y1);
            newLine.x2 = std::stoi(x2);
            newLine.y2 = std::stoi(y2);

            lines.push_back(newLine);
        }
    }
}
