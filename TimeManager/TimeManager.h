//
// Created by littlechai on 2022/5/13.
//

#ifndef ONECARDSYSTEM_TIMEMANAGER_H
#define ONECARDSYSTEM_TIMEMANAGER_H

#include <memory>

class TimeManager {
public:
    TimeManager();
    static std::shared_ptr<TimeManager> getInstance();

    int getMonth();
    int getYear();
    int getDay();
    void nextHour();
    void nextDay();
    void showTime();

private:
    int year;
    int month;
    int day;
    int hour;
};


#endif //ONECARDSYSTEM_TIMEMANAGER_H
