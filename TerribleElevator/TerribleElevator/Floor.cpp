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
void Floor::press_up() {
    up = true;
    numUp++;
}
void Floor::press_down() {
    down = true;
    numDown++;
}

