#include "Manager.hpp"
#include "Elevator.h"
#include "Floor.hpp"
#include "People.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
using namespace std;

// initialize the vector of floors
void Manager::initFloors() {
	for (int i = 0; i < FLOORS; i++) {
		floorList.push_back(new Floor(i + 1));
	}
}

// initialize the vector of people
void Manager::initPeople() {
	for (int i = 0; i < PEOPLE; i++) {
		peopleList.push_back(new People());
	}
}

// initialize the vector of elevators
void Manager::initElevators() {
	for (int i = 0; i < ELEVATORS; i++) {
		elevatorList.push_back(new Elevator());
	}
}