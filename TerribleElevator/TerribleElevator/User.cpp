#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>
#include "User.hpp"

using namespace std;

// WHEN USER PRESSES A FLOOR NUMBER, chooseFloor() NEEDS TO BE CALLED WITH FLOOR NUMBER PASSED IN
// SAME FOR OPEN DOOR BUTTON, doorOpen() NEEDS TO BE CALLED 

// contructors
User::User() {
    initialFloor = 1;   // default floor is 1
    goalFloor = 1;      // after listerner detects button clicked in ui, chooseFloor is called to change goalFloor
    direction = goalFloor - initialFloor < 0 ? -1 : 1;  // -1 if going down, 1 if going up
    holdOpen = false;
}

// methods
int User::get_goal_floor() { return goalFloor; }

int User::get_direction() { return direction; }

void User::chooseFloor(int floor) { goalFloor = floor; }

void User::doorOpen() { holdOpen = true; }


