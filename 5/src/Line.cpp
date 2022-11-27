#include "Line.h"
#include <cmath>

Line::Line() {
}

Line::~Line() {
}

std::vector<std::pair<short, short>> Line::getCoveredPoints() {

    std::vector<std::pair<short, short>> points;

    // first determine if its horizontal or vertical line
    if(!this->isDiagonal) {

        if(this->x1==this->x2) { // horizontal
            for(int i = 0; i < abs(this->y1-this->y2)+1;i++) {
                if(this->y1 < this->y2) {
                    points.push_back(std::pair<short, short>(this->x1,this->y1+i));
                }
                else {
                    points.push_back(std::pair<short, short>(this->x1,this->y2+i));
                }
            }
        }
        else if(this->y1==this->y2) { // vertical
            for(int i = 0; i < abs(this->x1-this->x2)+1;i++) {
                if(this->x1 < this->x2)
                    points.push_back(std::pair<short, short>(this->x1+i,this->y1));
                else
                    points.push_back(std::pair<short, short>(this->x2+i,this->y1));

            }
        }
    }
    return points;
}

std::vector<std::pair<short, short>> Line::getDiagonalCoveredPoints() {

    std::vector<std::pair<short, short>> points;

    if(this->isDiagonal) {

        for(int i = 0; i < abs(this->x1-this->x2)+1;i++) {

            short newX,newY = 0;

            if(this->x1 < this->x2) {
                newX = this->x1+i;
            }
            else {
                newX = this->x1-i;
            }
            if(this->y1 < this->y2) {
                newY = this->y1+i;
            }
            else {
                newY = this->y1-i;
            }
            points.push_back(std::pair<short, short>(newX,newY));
        }
    }
    return points;
}

