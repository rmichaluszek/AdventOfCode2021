#ifndef FISH_H
#define FISH_H

#include <bits/stdc++.h>


class Fish
{
    public:
        Fish();
        virtual ~Fish();

        std::vector<short> fishList;

        void ParseData(std::vector<std::string> data);

        int SimulateDay();

    protected:

    private:
};

#endif // FISH_H
