#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include "People.hpp"
#include "Floor.hpp"

using namespace std;

// contructors
Floor::Floor(int nfloorNum) : numPeopleUp(0), numPeopleDown(0), numUp(0), numDown(0) {
    nfloorNum = floorNum;
    totalPeople = numPeopleDown + numPeopleUp;
}

// methods
int Floor::press_up() {
    return ++numUp;
}

int Floor::press_down() {
    return ++numDown;
}

int Floor::get_num_people() { return totalPeople; }

void Floor::addPerson(People person) {
    if (person.get_direction < 0) numPeopleDown++;
    else if (person.get_direction > 0) numPeopleUp++;
    else { cout << "Error: new person's direction is 0." << endl; }
}

void Floor::elevator_arrive(int direction) {
    if (direction > 0) { numUp = 0; }
    else if (direction < 0) { numDown = 0; }
    else { cout << "Error: Floor can't clear presses because elevator direction is 0" << endl; }
}
