#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include "People.hpp"
using namespace std;

class Floor {
private:
    int floorNum        // floor number
	int numPeople;      // number of people waiting on a floor
    bool up;            // people waiting to go up
    int numUp;          // number of times up was pressed
    bool down;          // people waiting to go down
    int numDown;        // number of times down was pressed
    vector<People>;     // vector of people waiting
public:
	// constructors
    Floor(floorNum);
	// methods
    void press_up();    // person presses up
    void press_down();  // person presses down


};