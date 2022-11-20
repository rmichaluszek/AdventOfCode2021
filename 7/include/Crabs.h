#ifndef CRABS_H
#define CRABS_H

#include <bits/stdc++.h>

class Crabs
{
    public:
        Crabs();
        virtual ~Crabs();

        std::vector<short> crabsPositions;
        void ParseData(std::vector<std::string> data);

        int Solve();

    protected:

    private:
};

#endif // CRABS_H
