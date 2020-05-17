#ifndef USER_HPP
#define USER_HPP
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Globals.hpp"
using namespace std;

class User {
private:
    int initialFloor;        // current floor
    int goalFloor;           // destination floor
    int direction;           // going up = -1, going down = 1
    bool holdOpen;           // user holds door open
public:
    // constructors
    User();
    // methods
    int get_goal_floor();           // returns goal floor
    int get_direction();            // returns direction of person
    void chooseFloor(int floor);    // user button to go to a floor
    void doorOpen();                // method to set holdOpen to true
    // friends
    friend class Manager;

};
#endif