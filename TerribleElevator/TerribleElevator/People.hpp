#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;

class People {
private:
	int curFloor;           // current floor
    int goalFloor;          // destination floor
    int walkingSpeed;       // rate at which they walk
    int frustrationLevel;   // current frustration level
    int frustrationCap;     // frustration capacity 
public:
	// constructors
	People();
    // methods
    void randomize();       // randomizes properties
    

};