#ifndef DISPLAYS_H
#define DISPLAYS_H

#include <bits/stdc++.h>

class Displays
{
    public:
        Displays();
        virtual ~Displays();
        std::vector<std::string> outputs;
        std::vector<std::string> inputs;

        std::string SortInputWires(std::string data);

        void ParseData(std::vector<std::string> data);

        bool IsNumberInAnotherNumber(std::string a,std::string b);

        int GetUniqueNumbersAmount();
        long long GetOutputValues();

    protected:

    private:
};

#endif // DISPLAYS_H
