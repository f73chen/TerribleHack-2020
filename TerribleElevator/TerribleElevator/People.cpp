#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>
#include "People.hpp"

using namespace std;

// contructors
People::People() {
    initialFloor = rand() % FLOORS + 1;                 // default floor is 1
    goalFloor = rand() % FLOORS + 1;                    // random floor between 1-FLOORS inclusive
    while (goalFloor == initialFloor) {                 // generate again until goal is different from initial
        goalFloor = rand() % FLOORS + 1;
    }
    frustrationLevel = rand() % 6;                      // random frustration level between 0-5 inclusive
    direction = goalFloor - initialFloor < 0 ? -1 : 1;  // -1 if going down, 1 if going up
    pressAll = false;                                   // whether the person is evil and presses all buttons
    holdOpen = 0;                                       // whether the person holds open the door
}
People::People(int ninitialFloor) {
    initialFloor = ninitialFloor;                       // initial floor set to whatever is passed in
    goalFloor = rand() % FLOORS + 1;                    // random floor between 1-FLOORS inclusive
    while (goalFloor == initialFloor) {                 // generate again until goal is different from initial
        goalFloor = rand() % FLOORS + 1;
    }
    frustrationLevel = rand() % 6;                      // random frustration level between 0-5 inclusive
    direction = goalFloor - initialFloor < 0 ? -1 : 1;  // -1 if going down, 1 if going up
    pressAll = false;                                   // whether the person is evil and presses all buttons
    holdOpen = 0;                                       // whether the person holds open the door
}

// methods
int People::get_goal_floor() { return goalFloor; }

int People::get_frustration_level() { return frustrationLevel; }

int People::get_direction() { return direction; }

void People::set_frustration_level(int level) { frustrationLevel = level; }

void People::new_floor() { goalFloor = rand() % 10 + 1; }

void People::be_rude() {
    int level = get_frustration_level();
    if (frustrationLevel > 3) {
        pressAll = true;        // becomes evil
        frustrationLevel = 0;   // cathartic
    }
    // presses floor buttons so that it stops on every floor (Elevator class)
}
