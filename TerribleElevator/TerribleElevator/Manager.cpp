#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Manager.hpp"
using namespace std;

// initialize the vector of floors
void Manager::initFloors() {
	for (int i = 0; i < FLOORS; i++) {
		Floor* tempFloor = new Floor(i + 1);	// creates a pointer to a floor
		floorList.push_back(tempFloor);			// adds a new default floor
	}
}

// initialize the vector of elevators
void Manager::initElevators() {
	for (int i = 0; i < ELEVATORS; i++) {
		Elevator* tempElevator = new Elevator();	// creates a pointer to an elevator
		elevatorList.push_back(tempElevator);		// adds a new default elevator
	}
}

// initialize the vector of people
// NOTE: must be run after floors are generated, preferably elevators too
void Manager::initPeople() {
	srand(time(0)); // seeds the random number generator for the people objects
	for (int i = 0; i < PEOPLE; i++) {
		People* tempPerson = new People();		// this way, peopleList adds a pointer to a heap item
		peopleList.push_back(tempPerson);		// adds a new default person
		floorList[tempPerson->initialFloor-1]->peopleList.push_back(tempPerson); // add the person to their starting floor
	}
}

// the main program cycle, returns integer error codes
int Manager::run() {
	// every cycle, checks the actions of everyone in one floor and sends it to the floor
	// checks the actions of everyone in one elevator and sends it to the elevator
	// each cycle is equal to 1 second
	// new people are generated into peopleList, copied into floorList, then walks into elevatorList
	// ADJUST NUMBERS SO TIMING IS MORE REALISTIC

	// testing output to make sure people are put into their corresponding floor lists
	for (Floor* eachFloor : floorList) {
		cout << "Floor: " << eachFloor->floorNum << endl;
		for (People* tempPerson : eachFloor->peopleList) {
			cout << "Initial floor: " << tempPerson->initialFloor << ", goal floor: " << tempPerson->goalFloor << endl;
		}
	}

	/*while (true) {

	}*/
	return 0;
}

void Manager::test() {
	peopleList = {};		// resets all list contents
	floorList = {};
	elevatorList = {};

	// first, generate the list of floors
	initFloors();
	for (int i = 0; i < FLOORS; i++) { cout << "Floor number: " << floorList[i]->floorNum << endl; }
	
	// then, generate the list of elevators
	initElevators();
	for (int i = 0; i < ELEVATORS; i++) { cout << "Elevator location: " << elevatorList[i]->floor<< endl; }
	
	// finally, generate random people and put them on the corresponding starting floors
	initPeople();
	for (int i = 0; i < PEOPLE; i++) { cout << "People " << i << ": Initial floor: " << peopleList[i]->initialFloor << ", goal floor: " << peopleList[i]->goalFloor << endl; }

	run();
}