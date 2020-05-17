#ifndef FLOOR_HPP
#define FLOOR_HPP
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include "People.hpp"
using namespace std;

class Floor {
private:
    int floorNum;                 // floor number
    int numPeopleUp;             // number of people needing to go up
    int numPeopleDown;           // number of people needing to go down
    int totalPeople;             // total number of people waiting on floor
    int numUp;                   // number of times up was pressed
    int numDown;                 // number of times down was pressed
public:
    // constructors
    Floor(int floorNum);
    // methods
    int press_up();                         // person presses up
    int press_down();                       // person presses down
    int get_num_people();                   // returns number of people waiting
    void addPerson(People person);          // increments numPeople
    void elevator_arrive(int direction);    // resets button pressed
    // friends
    friend class Manager;
};
#endif