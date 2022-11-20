#include "DataLoader.h"

DataLoader::DataLoader() {

}

DataLoader::~DataLoader() {

}

std::vector<std::string> DataLoader::GetData() {

    std::vector<std::string> data;

    bool inputEnabled = true;
    while(inputEnabled) {

        std::string l = "";
        getline(std::cin,l);

        if(l.length()<= 0)
            inputEnabled = false;
        else
            data.push_back(l);
    }
    return data;
}
