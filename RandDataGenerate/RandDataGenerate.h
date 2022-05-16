//
// Created by littlechai on 2022/5/13.
//

#ifndef ONECARDSYSTEM_RANDDATAGENERATE_H
#define ONECARDSYSTEM_RANDDATAGENERATE_H

#include "../CardManager/CardManager.h"
#include "../RandDataGenerate/RandDataGenerate.h"
#include <vector>

enum class IdentityEnum;
enum class DepartmentEnum;
enum class StateEnum {
    None = 0,
    Charge = 1,
    Logout = 2,
};
struct PeopleData {
    std::string name;
    std::string sex;
    std::string Id;
    IdentityEnum identity;
    DepartmentEnum department;
    StateEnum state;
};
struct CarData {
    std::string Id;
    std::string name;
    std::string version;
    int maxPeopleNumber;
};
class RandDataGenerate {
public:
    std::vector<PeopleData> generatePeopleNumber();
    std::vector<CarData> generateCarNumber();

    std::pair<std::string, std::string> generateSexAndName();
    std::string generateId();

    RandDataGenerate(int peopleNumber, int carNumber);
private:
    std::vector<PeopleData> peopleData;
    std::vector<CarData> carData;

    void generatePeopleData(int number);
    void generateCarPeopleData(int number);


};


#endif //ONECARDSYSTEM_RANDDATAGENERATE_H
