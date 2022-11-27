#ifndef LINE_H
#define LINE_H

#include <bits/stdc++.h>

class Line
{
    public:
        Line();
        virtual ~Line();

        short x1, x2, y1, y2;
        bool isDiagonal = false;

        std::vector<std::pair<short, short>> getCoveredPoints();
        std::vector<std::pair<short, short>> getDiagonalCoveredPoints();

    protected:

    private:

};

#endif // LINE_H
