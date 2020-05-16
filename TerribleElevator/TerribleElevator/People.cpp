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
int People::getFloor() {return curFloor;}
int People::getGoalFloor() {return goalFloor;}
int People::getFrustrationLevel() {return frustrationLevel;}
void People::setFrustrationLevel(int level) {frustrationLevel = level;}
void People::newFloor() {goalFloor = rand() % 10 + 1;}
