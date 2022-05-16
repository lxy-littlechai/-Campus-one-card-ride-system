#include <iostream>
#include <unistd.h>
#include "RandDataGenerate/RandDataGenerate.h"
#include "TimeManager/TimeManager.h"
#include "CardManager/CardManager.h"
#include "CarManager/CarManager.h"
int main() {
    srand(time(0));
    RandDataGenerate randData(300, 10);
    CardManager cardManager;
    while(TimeManager::getInstance()->getYear() <= 2023) {
        if(TimeManager::getInstance()->getDay() == 1) {
            int month = TimeManager::getInstance()->getMonth()-1 < 1 ? 12 : TimeManager::getInstance()->getMonth()-1;
            cardManager.showMessage(month);
            sleep(5);
        }
        if(TimeManager::getInstance()->getMonth() == 1){

            cardManager.clearMonthUse();

        }
        TimeManager::getInstance()->showTime();

        auto peopleData = randData.generatePeopleNumber();

        auto carData = randData.generateCarNumber();
        CarManager car1(carData[0]);
        CarManager car2(carData[1]);
        car1.showMessage();
        car2.showMessage();

        for(auto person: peopleData) {
            if(!cardManager.checkIfRegister(person.Id)) {
                cardManager.registerCard(
                        person.name,
                        person.sex,
                        person.Id,
                        person.identity,
                        person.department
                        );
                //Every card be charged with 10
                cardManager.charge(person.Id, 10);
            }
        }
        for(auto person: peopleData) {
            Card card( person.name,
                       person.sex,
                       person.Id,
                       person.identity,
                       person.department);

            if(cardManager.consumeCheck(card.getId())) {
                if(car1.getPerson() < car1.getMaxPeopleNumber()){
                    car1.addPerson();
                }
                else if(car2.getPerson() < car2.getMaxPeopleNumber()) {
                    car2.addPerson();
                }
            }
        }

        TimeManager::getInstance()->nextHour();


        sleep(0.5);
    }
    return 0;
}
