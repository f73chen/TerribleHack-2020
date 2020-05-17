#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "People.hpp"

using namespace std;

// contructors
People::People() {
    initialFloor = rand() % FLOORS + 1;     // default floor is 1
    goalFloor = rand() % FLOORS + 1;        // random floor between 1-FLOORS inclusive
    while (goalFloor == initialFloor) {     // generate again until goal is different from initial
        goalFloor = rand() % FLOORS + 1;
    }
    holdOpen = 0;
    id = 0;                                 // the default value for NPC
}
People::People(int ninitialFloor) {
    initialFloor = ninitialFloor;           // initial floor set to whatever is passed in
    goalFloor = rand() % FLOORS + 1;        // random floor between 1-FLOORS inclusive
    while (goalFloor == initialFloor) {     // generate again until goal is different from initial
        goalFloor = rand() % FLOORS + 1;
    }
    holdOpen = 0;
    id = 0;                                 // the default value for NPCs
}

// assigns this person a new goal floor. Only used to represent user
void People::setGoalFloor(int goal) {
    goalFloor = goal;
}