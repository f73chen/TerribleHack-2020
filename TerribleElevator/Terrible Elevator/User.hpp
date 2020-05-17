#ifndef USER_HPP
#define USER_HPP
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "Globals.hpp"
using namespace std;

class User {
private:
    int initialFloor;       // current floor
    int goalFloor;          // destination floor
    int holdOpen;           // user holds door open
    int id;                 // id tag, must not be 0
public:
    // constructors
    User();
    // methods
    int getCurrentFloor();          // returns current floor
    int get_goal_floor();           // returns goal floor
    void setGoalFloor(int floor);    // user button to go to a floor
    void doorOpen();                // every click holds the door open for longer

    // friends
    friend class Manager;
};
#endif