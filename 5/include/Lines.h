#ifndef LINES_H
#define LINES_H

#include "Line.h"
#include <bits/stdc++.h>

class Lines
{
    public:
        Lines();
        virtual ~Lines();

        void ParseData(std::vector<std::string> data);

        std::vector<Line> lines;

    protected:

    private:
};

#endif // LINES_H
