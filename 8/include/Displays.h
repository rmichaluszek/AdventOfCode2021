#ifndef DISPLAYS_H
#define DISPLAYS_H

#include <bits/stdc++.h>

class Displays
{
    public:
        Displays();
        virtual ~Displays();
        std::vector<std::string> outputs;
        void ParseData(std::vector<std::string> data);
        int GetUniqueNumbersAmount();

    protected:

    private:
};

#endif // DISPLAYS_H
