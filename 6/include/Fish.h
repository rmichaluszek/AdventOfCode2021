#ifndef FISH_H
#define FISH_H

#include <bits/stdc++.h>


class Fish
{
    public:
        Fish();
        virtual ~Fish();

        // now it will hold sum of fish that have the same days left to reproduce
        long long fishList[9] = { 0 };

        void ParseData(std::vector<std::string> data);
        void SimulateDay();
        long long GetFishCount();

    protected:

    private:
};

#endif // FISH_H
