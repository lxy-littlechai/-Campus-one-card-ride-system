//
// Created by littlechai on 2022/5/13.
//

#ifndef ONECARDSYSTEM_CARDMANAGER_H
#define ONECARDSYSTEM_CARDMANAGER_H
#include <iostream>
#include <vector>
#include <memory>

enum class IdentityEnum {
    Teacher = 0,
    Student = 1,
    Family = 2,
};
enum class DepartmentEnum {
    None = 0,
    Computer = 1,
    Electronic = 2,
    Foreign = 3,
};
class CardManager;

class Card {
    friend CardManager;

public:
    Card(std::string name, std::string sex, std::string Id, IdentityEnum identity, DepartmentEnum department);
    void showMessage(bool allDisplay, int month = 0);
    bool consumeCheck();

    std::string getId();


private:
    std::string name;
    std::string sex;
    std::string Id;
    IdentityEnum identity;
    DepartmentEnum department;
    int account;
    int useTimesMonth[13];

    bool consume();
    void charge(int value);
    void clearMonthUse();

};
class CardManager {
public:

    void charge(std::string Id, int value);
    void registerCard(std::string name, std::string sex, std::string Id, IdentityEnum identity, DepartmentEnum department);
    void logout(std::string Id);
    bool checkIfRegister(std::string Id);
    bool consumeCheck(std::string Id);
    void showMessage(int month);
    void clearMonthUse();

private:
    std::vector<Card> cardManager;
};


#endif //ONECARDSYSTEM_CARDMANAGER_H
