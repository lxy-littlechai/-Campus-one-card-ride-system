//
// Created by littlechai on 2022/5/13.
//

#include <iostream>
#include <memory>
#include <map>
#include "TimeManager.h"

TimeManager::TimeManager() {
    year = 2022;
    month = 5;
    day = 13;
    hour = 8;
}

std::shared_ptr<TimeManager> TimeManager::getInstance() {
    static std::shared_ptr<TimeManager> instance = std::shared_ptr<TimeManager>(new TimeManager());
    return instance;
}
int TimeManager::getDay() {
    return day;
}

int TimeManager::getMonth() {
    return month;
}

int TimeManager::getYear() {
    return year;
}

void TimeManager::nextHour() {
    hour ++;
    if(hour > 18) {
        nextDay();
        hour = 8;
    }
}
void TimeManager::nextDay() {
    day ++;
    static std::map<int,int> month2Day = {
            {1, 31}, {2, 28}, {3, 31}, {4, 30},
            {5, 31}, {6, 30}, {7, 31}, {8, 31},
            {9, 30}, {10, 31}, {11, 30}, {12, 31}
    };
    if(month == 2) {
        if((year%4 == 0 && year%100 != 0) || year%400 == 0) {
            month2Day[2] = 28;
        }
        else {
            month2Day[2] = 29;
        }
    }

    if(day > month2Day[month]) {
        day = 1;
        month ++;
        if(month > 12) {
            month = 1;
            year ++;
        }
    }
}

void TimeManager::showTime() {
    std::cout << year << "-" << month << "-" << day << "-" << hour << std::endl;
}
