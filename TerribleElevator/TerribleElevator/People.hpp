#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;

class People {
private:
	int curFloor;            // current floor
    int goalFloor;           // destination floor
    int frustrationLevel;    // current frustration level
    int frustrationCap;      // frustration capacity 
public:
	// constructors
    People();
	People(int initialFloor);
    // methods
    int getFloor();                         // returns current floor
    int getGoalFloor();                     // returns goal floor
    int getFrustrationLevel();              // returns frustration level
    void setFrustrationLevel(int level);    // sets frustration level to passed parameter
    void newFloor();                        // sets new goal floor to random floor

};