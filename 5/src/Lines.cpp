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

        short x1 = std::stoi(lineStart.substr(0, lineStart.find(pointsDelimiter)));
        short y1 = std::stoi(lineStart.substr(lineStart.find(pointsDelimiter)+1, lineStart.find(pointsDelimiter)+2));

        short x2 = std::stoi(lineEnd.substr(0, lineEnd.find(pointsDelimiter)));
        short y2 = std::stoi(lineEnd.substr(lineEnd.find(pointsDelimiter)+1, lineEnd.find(pointsDelimiter)+2));

        if (x1==x2 || y1==y2) {
            // horizontal or vertical
            Line newLine;
            newLine.x1 = x1;
            newLine.y1 = y1;
            newLine.x2 = x2;
            newLine.y2 = y2;

            lines.push_back(newLine);
        } else if (abs(x1-x2) == abs(y1-y2)) {
            // diagonal at 45 degrees
            Line newLine;
            newLine.isDiagonal = true;
            newLine.x1 = x1;
            newLine.y1 = y1;
            newLine.x2 = x2;
            newLine.y2 = y2;

            lines.push_back(newLine);
        }
    }
}
