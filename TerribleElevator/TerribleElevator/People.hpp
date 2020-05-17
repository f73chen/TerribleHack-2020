#ifndef PEOPLE_HPP
#define PEOPLE_HPP
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include "Globals.hpp"
using namespace std;

class People {
private:
    int initialFloor;        // current floor
    int goalFloor;           // destination floor
    int frustrationLevel;    // current frustration level
    int direction;           // going up = -1, going down = 1
    bool pressAll;           // manager needs to handle pressing all buttons
    int holdOpen;            // manager needs to handle seconds door is held open
public:
    // constructors
    People();
    People(int initialFloor);
    // methods
    int get_goal_floor();                     // returns goal floor
    int get_frustration_level();              // returns frustration level
    int get_direction();                      // returns direction of person
    void set_frustration_level(int level);    // sets frustration level to passed parameter
    void new_floor();                         // sets new goal floor to random floor
    void be_rude();                           // person does something rude based on frustration level
    // friends
    friend class Manager;

};
#endif