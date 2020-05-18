#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "User.hpp"

using namespace std;

// WHEN USER PRESSES A FLOOR NUMBER, chooseFloor() NEEDS TO BE CALLED WITH FLOOR NUMBER PASSED IN
// SAME FOR OPEN DOOR BUTTON, doorOpen() NEEDS TO BE CALLED 

// contructors
User::User() {
    initialFloor = 1;   // default floor is 1
    goalFloor = 1;      // after listerner detects button clicked in ui, chooseFloor is called to change goalFloor
    holdOpen = 0;       // not holding open doors
    id = 1;             // sets this user apart from other people objects
}

// methods
int User::getCurrentFloor() {
    if (goalFloor + 3 <= 7) {
        return goalFloor + 3;
    }
    else {
        return goalFloor + (7 - (goalFloor + 3));
    }
}

int User::get_goal_floor() { return goalFloor; }

void User::setGoalFloor(int floor) { goalFloor = floor; }

void User::doorOpen() { holdOpen++; }


