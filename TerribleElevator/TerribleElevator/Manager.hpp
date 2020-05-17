#ifndef MANAGER_HPP
#define MANAGER_HPP
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Floor.hpp"
#include "People.hpp"
#include "Elevator.hpp"
using namespace std;

class Manager {
private:
	vector<People*> peopleList;		// list of all people objects
	vector<Floor*> floorList;		// list of floor objects 
	vector<Elevator*> elevatorList;	// list of all elevator objects
public:
	// default constructor
	Manager() { initFloors(); initPeople(); initElevators(); }

	// initialize the vector of people
	void initPeople();

	// initialize the vector of floors
	void initFloors();

	// initialize the vector of elevators
	void initElevators();

	// the main program cycle, returns integer error codes
	int run();

	// in-house tests of the contents of each list
	void test();
};
#endif