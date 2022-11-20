#include "Line.h"
#include <cmath>

Line::Line() {
}

Line::~Line() {
}

std::vector<std::pair<short, short>> Line::getCoveredPoints() {
    // first determine if its horizontal or vertical line
    std::vector<std::pair<short, short>> points;

    if(this->x1==this->x2) { // horizontal
        for(int i = 0; i < abs(this->y1-this->y2)+1;i++) {
            if(this->y1 < this->y2) {
                points.push_back(std::pair<short, short>(x1,this->y1+i));
            }
            else {
                points.push_back(std::pair<short, short>(x1,this->y2+i));
            }
        }
    }
    else if(this->y1==this->y2) { // vertical
        for(int i = 0; i < abs(this->x1-this->x2)+1;i++) {
            if(this->x1 < this->x2)
                points.push_back(std::pair<short, short>(this->x1+i,y1));
            else
                points.push_back(std::pair<short, short>(this->x2+i,y1));

        }
    }
    return points;
}
