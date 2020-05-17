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
	// @@@@@@@@@@ADJUST NUMBERS SO TIMING IS MORE REALISTIC

	// testing output to make sure people are put into their corresponding floor lists
	/*for (Floor* eachFloor : floorList) {
		cout << "Floor: " << eachFloor->floorNum << endl;
		for (People* tempPerson : eachFloor->peopleList) {
			cout << "Initial floor: " << tempPerson->initialFloor << ", goal floor: " << tempPerson->goalFloor << endl;
		}
	}*/

	int cycleCounter = 0;
	for(int round = 0; round < 20; round++) { // USUALLY SET TO WHILE TRUE
		cout << "Cycle " << cycleCounter << ": " << endl;
		vector<int> numCalls = {0, 0}; // @@@@@@@@@@@SUM THE CALLS IN EACH ELEVATOR'S PATH THAT IT CAN ACT ON
		
		cout << "Checking whether elevators are at a floor: " << endl;
		// int nfloor, int nspeed, int ndirection, bool ncanMove, vector<bool> nbuttonsPressed, int nnextStop, int nstoppingDistance, vector<People*> npeopleList
		// elevatorList[0] = new Elevator(1, 2, 1, true, { false, false, false, false, false, false, false }, 3, 1, {});
		// @@@@@@@@ SHOULD BE ABLE TO MAKE CUSTOM CARS BY INPUTTING VALUES
		// @@@@@@@ SHOULD BE ABLE TO CALCULATE NEXT SPEED > 0 IF INITIAL SPEED IS 0 BUT NOT AT DESTINATION
		for (int i = 0; i < ELEVATORS; i++) {
			Elevator* tempElevator = elevatorList[i];
			int currentFloor = tempElevator->floor;
			if (tempElevator->floor == tempElevator->nextStop) { // arrived at next destination
				cout << "Elevator " << i << " has arrived at next destination floor " << currentFloor << endl;
				cout << "Changing speed and direction to 0" << endl;
				tempElevator->speed = 0;
				tempElevator->direction = 0;
			}
			else { //if on route
				cout << "Elevator " << i << " is travelling from floor " << currentFloor << " in direction " << tempElevator->direction << " at distance " << tempElevator->distanceToNextFloor << endl;
				tempElevator->distanceToNextFloor -= tempElevator->speed;
				if (tempElevator->distanceToNextFloor <= 0) { // if moves by one floor in the next cycle
					tempElevator->floor += tempElevator->direction; // set floor number to its next arrival
					tempElevator->nextSpeed(numCalls[i]); // reset / calculate its next movement speed
					cout << "Next speed is: " << tempElevator->speed << endl; // what the speed to the next floor is calculated for that car
					// @@@@@@@ THERE SHOULD STILL BE SOME SPEED IF THE GAP IS 1 FLOOR (1-6, STUCK AT F5)
					// @@@@@@@ NEXTSPEED SHOULDN'T BE NEGATIVE (1-3, SPEED 2)
					tempElevator->distanceToNextFloor = DIST_BTW_FLOORS; // reset its distance to the next floor
				}
			}
		}

		cycleCounter++;
	}
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