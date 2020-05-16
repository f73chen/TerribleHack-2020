#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include "People.hpp"

using namespace std;

// contructors
People::People(floorNum) : numPeople(0), up(false), down(false), numUp(0), numDown(0) {
    floorNum = floorNum;
}

// methods
int Floor::press_up() {
    return ++numUp;
}

int Floor::press_down() {
    return ++numDown;
}

int get_num_people() {return totalPeople;}

void Floor::addPerson(People person) {
    if(person.get_direction < 0) numPeopleDown++;
    else numPeopleUp++;
}

void Floor::elevator_arrive(int direction) {
    if(direction > 0) {
        numUp = 0;
        numPeopleUp = 0;
    }
    else {
        numDown = 0;
        numPeopleDown = 0;
    }
}
