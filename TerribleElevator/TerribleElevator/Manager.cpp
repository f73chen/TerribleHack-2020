#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include "Manager.hpp"
#include "Elevator.h"
#include "Floor.hpp"
#include "People.hpp"
using namespace std;

// initialize the vector of people
void Manager::initPeople() {
	for (int i = 0; i < PEOPLE; i++) {
		People* tempPerson = new People();		// this way, peopleList adds a pointer to a heap item
		peopleList.push_back(tempPerson);		// adds a new default person
	}
}

// initialize the vector of floors
void Manager::initFloors() {
	for (int i = 0; i < FLOORS; i++) {
		Floor* tempFloor = new Floor(i + 1);	// creates a pointer to a floor
		floorList.push_back(tempFloor);			// adds a new default floor
		floorPeopleList.push_back({});			// adds a new list of people on that floor
	}
}

// initialize the vector of elevators
void Manager::initElevators() {
	for (int i = 0; i < ELEVATORS; i++) {
		Elevator* tempElevator = new Elevator();	// creates a pointer to an elevator
		elevatorList.push_back(tempElevator);		// adds a new default elevator
		elevatorPeopleList.push_back({});			// adds a new list of people in that elevator
	}
}

// the main program cycle, returns integer error codes
int Manager::run() {
	// every cycle, checks the actions of everyone in one floor and sends it to the floor
	// checks the actions of everyone in one elevator and sends it to the elevator
	// each cycle is equal to 1 second
	// ADJUST NUMBERS SO TIMING IS MORE REALISTIC

	for (People* tempPerson : peopleList) { // start by copying the pointers of people to their corresponding floor list
		floorPeopleList[tempPerson->initialFloor - 1].push_back(tempPerson);
	} // make sure to update each list after an action involving that floor is completed

	/*while (true) {

	}*/
}

void Manager::test() {
	peopleList = {};		// resets all list contents
	floorList = {};
	elevatorList = {};
	floorPeopleList = {};
	elevatorPeopleList = {};

	initPeople();
	for (int i = 0; i < PEOPLE; i++) { cout << "People " << i << ": Initial floor: " << peopleList[i]->initialFloor << endl; }
	/*initFloors();
	initElevators();
	run();*/
}