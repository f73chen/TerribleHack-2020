#ifndef MANAGER_HPP
#define MANAGER_HPP
#include "Elevator.h"
#include "Floor.hpp"
#include "People.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
using namespace std;

int MAX_SPEED = 5;		// max speed of each elevator car
int CAPACITY = 8;		// max capacity of each elevator car
int FLOORS = 7;			// total number of floors in the building
int PEOPLE = 10;		// total number of NPC people
int ELEVATORS = 2;		// total number of elevators

class Manager{
private:
	vector<Floor*> floorList;		// list of floor objects 
	vector<People*> peopleList;		// list of all people objects
	vector<Elevator*> elevatorList;	// list of all elevator objects
public:
	// default constructor
	Manager() { initFloors(); initPeople(); initElevators(); }

	// initialize the vector of floors
	void initFloors();

	// initialize the vector of people
	void initPeople();

	// initialize the vector of elevators
	void initElevators();
};
#endif