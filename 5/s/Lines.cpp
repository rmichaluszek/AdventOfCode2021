#include "Lines.h"

Lines::Lines() {

}

Lines::~Lines() {

}

void ParseData(std::vector<std::string> data) {

    for(size_t i = 0; i != data.size(); i++) {
        // 0,9 -> 5,9 // data looks like this

        std::string linesDelimiter = " -> ";
        std::string lineStart = data[i].substr(0, data[i].find(linesDelimiter));
        std::string lineEnd = data[i].substr(data[i].find(linesDelimiter)+4, data[i].length());

    }
}
