#ifndef PEOPLE_HPP
#define PEOPLE_HPP
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

class People {
private:
    int initialFloor;       // current floor
    int goalFloor;          // destination floor
    int holdOpen = 0;       // proxy for the user to hold door open
    int id;                 // used to differentiate NPC from user: will make a people object to represent the person
public:
    // constructors
    People();
    People(int initialFloor);

    // assigns this person a new goal floor, can be used to reset the person representing user
    void setGoalFloor(int goal);

    friend class Manager;
    friend class User;
};
#endif