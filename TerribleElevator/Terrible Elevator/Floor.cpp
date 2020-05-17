#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "Floor.hpp"

using namespace std;

// contructors
Floor::Floor(int nfloorNum) : numUp(0), numDown(0), totalPeople(0) {
    floorNum = nfloorNum;
}

int Floor::get_num_people() { return totalPeople; }