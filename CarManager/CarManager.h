//
// Created by littlechai on 2022/5/13.
//

#ifndef ONECARDSYSTEM_CARMANAGER_H
#define ONECARDSYSTEM_CARMANAGER_H

#include <iostream>
#include <vector>
#include "../RandDataGenerate/RandDataGenerate.h"



class CarManager {
public:
    CarManager(CarData data);

    void showMessage();

    void addPerson();
    int getPerson();
    int getMaxPeopleNumber();

private:
    std::string Id;
    std::string name;
    std::string version;
    int maxPeopleNumber;
    int currentNumber;
};


#endif //ONECARDSYSTEM_CARMANAGER_H
