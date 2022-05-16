//
// Created by littlechai on 2022/5/13.
//

#include "CardManager.h"
#include "../TimeManager/TimeManager.h"

Card::Card(std::string name, std::string sex, std::string Id, IdentityEnum identity, DepartmentEnum department) {
    this->name = name;
    this->sex = sex;
    this->Id = Id;
    this->identity = identity;
    this->department = department;
    this->account = 0;
    for(int i = 1;i <= 12;i ++) {
        this->useTimesMonth[i] = 0;
    }

}
bool Card::consume() {
    int month = TimeManager::getInstance()->getMonth();
    if(account < 2) {
        std::cout << "余额不足" << std::endl;
        return false;
    }
    else {
        account -= 2;
        useTimesMonth[month] ++;
        if(account <= 5) {
            std::cout << "余额过低，及时充值" << std::endl;
        }
        return true;
    }
}
bool Card::consumeCheck() {
    showMessage(false);
    int month = TimeManager::getInstance()->getMonth();
    //useTimesMonth[month] ++;
    if(identity == IdentityEnum::Teacher) {
        useTimesMonth[month] ++;
        return true;
    }
    else if (identity == IdentityEnum::Family) {
        if(useTimesMonth[month] < 19){
            useTimesMonth[month] ++;
            return true;
        }
        else if(useTimesMonth[month] == 19) {
            std::cout << "最后一次免费乘车" << std::endl;
            useTimesMonth[month] ++;
            return true;
        }
        else if(useTimesMonth[month] == 20) {
            std::cout << "本次开始收费" << std::endl;
            return consume();
        }
        else if(useTimesMonth[month] > 20){
            return consume();
        }
    }
    else if(identity == IdentityEnum::Student) {
        return consume();
    }
}
void Card::showMessage(bool allDisplay, int month) {
    std::cout << "姓名: " << name << " 余额: "<< account << " " ;
    if(identity == IdentityEnum::Family || allDisplay) {
        if(month == 0){
            month = TimeManager::getInstance()->getMonth();
        }
        std::cout << month << "月已乘坐次数: " << useTimesMonth[month] << std::endl;
    }
    else {
        std::cout << std::endl;
    }

}

std::string Card::getId() {
    return Id;
}

void Card::charge(int value) {
    account += value;
}

void Card::clearMonthUse() {
    for(int i = 1;i <= 12;i ++) {
        useTimesMonth[i] = 0;
    }
}

void CardManager::registerCard(std::string name, std::string sex, std::string Id, IdentityEnum identity, DepartmentEnum department) {
    for(auto user: cardManager) {
        if(user.getId() == Id) {
            std::cout << "该账户已存在" << std::endl;
            return ;
        }
    }
    Card card(name, sex, Id, identity, department);
    cardManager.push_back(card);
    std::cout << "账户: " << name << " Id:" << Id << " 创建成功" << std::endl;
}

void CardManager::charge(std::string Id, int value) {
    for(auto it = cardManager.begin();it !=cardManager.end();it ++) {
        if(it->getId() == Id) {
            it->charge(value);
            std::cout << "充值成功" << std::endl;
            return ;
        }
    }
}

void CardManager::logout(std::string Id) {
    for(auto it = cardManager.begin();it !=cardManager.end();it ++) {
        if(it->getId() == Id) {
            cardManager.erase(it);
            std::cout << "注销成功" << std::endl;
            return ;
        }
    }
}

bool CardManager::checkIfRegister(std::string Id) {
    for(auto it = cardManager.begin();it !=cardManager.end();it ++) {
        if(it->getId() == Id) {
            return true;
        }
    }
    return false;
}

bool CardManager::consumeCheck(std::string Id) {
    for(auto it = cardManager.begin();it !=cardManager.end();it ++) {
        if(it->getId() == Id) {
            return it->consumeCheck();
        }
    }
}

void CardManager::showMessage(int month) {
    for(auto card: cardManager) {
        card.showMessage(true, month);
    }
}

void CardManager::clearMonthUse() {
    for(auto it = cardManager.begin();it !=cardManager.end();it ++) {
        it->clearMonthUse();

    }
}
