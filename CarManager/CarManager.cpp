//
// Created by littlechai on 2022/5/13.
//

#include "CarManager.h"

CarManager::CarManager(CarData data) {
    this->Id = data.Id;
    this->name = data.name;
    this->version = data.version;
    this->maxPeopleNumber = data.maxPeopleNumber;
    this->currentNumber = 0;
}

void CarManager::showMessage() {
    std::cout << "车牌号: "<< Id << "\n 驾驶员姓名: " << name << "\n 型号: " << version << "\n 最大乘客量" << maxPeopleNumber << "\n";
    std::cout << std::endl;
}

void CarManager::addPerson() {
    currentNumber ++;
}
int CarManager::getPerson() {
    return currentNumber;
}
int CarManager::getMaxPeopleNumber() {
    return maxPeopleNumber;
}
