#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include "People.hpp"

using namespace std;

// contructors
People::People() {
    curFloor = 1;                       // default contructor makes current floor 1
    goalFloor = rand() % 10 + 1;        // random floor between 1-10 inclusive
    frustrationLevel = 1;               // random frustration level between 1-5 inclusive
    frustrationCap = 5;                 // max frustration is 5
}
People::People(int initialFloor) {
    curFloor = initialFloor;            // current floor set to whatever is passed in
    goalFloor = rand() % 10 + 1;        // random floor between 1-10 inclusive
    frustrationLevel = 1;               // random frustration level between 1-5 inclusive
    frustrationCap = 5;                 // max frustration is 5
}

// methods
int People::get_floor() {return curFloor;}
int People::get_goal_floor() {return goalFloor;}
int People::get_frustration_level() {return frustrationLevel;}
void People::set_frustration_level(int level) {frustrationLevel = level;}
void People::new_floor() {goalFloor = rand() % 10 + 1;}
void People::be_rude() {
    int level = get_frustration_level();
    // hold door close
    // presses floor buttons so that it stops on every floor
}
