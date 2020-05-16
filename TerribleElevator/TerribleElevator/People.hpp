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
    int get_floor();                          // returns current floor
    int get_goal_floor();                     // returns goal floor
    int get_frustration_level();              // returns frustration level
    void set_frustration_level(int level);    // sets frustration level to passed parameter
    void new_floor();                         // sets new goal floor to random floor
    void be_rude();                           // person does something rude based on frustration level

};