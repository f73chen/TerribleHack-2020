#ifndef FLOOR_HPP
#define FLOOR_HPP
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>
#include "People.hpp"
using namespace std;

class Floor {
private:
    int floorNum;               // floor number
    int totalPeople;            // total number of people waiting on floor
    int numUp;                  // number of times up was pressed
    int numDown;                // number of times down was pressed
    vector<People*> peopleList; // list of people on that floor

public:
    // constructors
    Floor(int floorNum);
    // methods
    int get_num_people();                   // returns number of people waiting
    // friends
    friend class Manager;
};
#endif