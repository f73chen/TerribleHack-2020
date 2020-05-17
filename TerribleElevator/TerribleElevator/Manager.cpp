#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
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
		if (tempPerson->goalFloor > tempPerson->initialFloor) {
			floorList[tempPerson->initialFloor - 1]->numUp++; // new person request to go up
		}
		else {
			floorList[tempPerson->initialFloor - 1]->numDown++; // new person request to go down
		}
	}
}

// the main program cycle, returns integer error codes
int Manager::run() {
	// every cycle, checks the actions of everyone in one floor and sends it to the floor
	// checks the actions of everyone in one elevator and sends it to the elevator
	// each cycle is equal to 1 second
	// new people are generated into peopleList, copied into floorList, then walks into elevatorList

	// testing output to make sure people are put into their corresponding floor lists
	/*for (Floor* eachFloor : floorList) {
		cout << "Floor: " << eachFloor->floorNum << ", numUp: " << eachFloor->numUp << ", numDown: " << eachFloor->numDown << endl;
		for (People* tempPerson : eachFloor->peopleList) {
			cout << "Initial floor: " << tempPerson->initialFloor << ", goal floor: " << tempPerson->goalFloor << endl;
		}
	}*/

	// int nfloor, int nspeed, int ndirection, bool ncanMove, vector<bool> nbuttonsPressed, int nnextStop, vector<People*> npeopleList
	Elevator* tempNewEl = new Elevator(5, 6, -1, true, { false, false, false, false, false, false, false }, 2, {});
	elevatorList[1] = tempNewEl;
	vector<int> doorHoldTime(ELEVATORS, 0); // if the elevator is being held for its door

	for(int round = 0; round < 20; round++) { // USUALLY SET TO WHILE TRUE INSTEAD OF A FOR LOOP
		cout << endl << "Cycle " << round << ": " << endl;
		vector<int> numCalls = {0, 0};
		
		//cout << "Checking whether elevators are at a floor: " << endl;
		for (int i = 0; i < ELEVATORS; i++) { // for each elevator in operation
			Elevator* tempElevator = elevatorList[i];
			if (doorHoldTime[i] > 0) { // count down by one and ignore all activities
				cout << "Elevator " << i << " has countdown of " << doorHoldTime[i] << " seconds" << endl;
				doorHoldTime[i]--; 
			}
			else { // if not being held
				int currentFloor = tempElevator->floor;
				if (currentFloor == tempElevator->nextStop) { // arrived at next destination
					cout << "Elevator " << i << " arrived at floor " << currentFloor << endl;
					elevatorArrived(tempElevator); 
					doorHoldTime[i] = DOOR_HOLD; // reset doorHoldTime counter
				}
				else { //if on route
					//cout << "Elevator " << i << " from " << currentFloor << " direction " << tempElevator->direction << " destination " << tempElevator->nextStop << " distance " << tempElevator->distanceToNextFloor << " speed " << tempElevator->speed << endl;
					tempElevator->distanceToNextFloor -= tempElevator->speed;
					if (tempElevator->distanceToNextFloor <= 0) { // if moves by one floor in the next cycle
						tempElevator->floor += tempElevator->direction; // set floor number to its next arrival
						tempElevator->distanceToNextFloor = DIST_BTW_FLOORS; // reset its distance to the next floor
					}
				}
			}
		}
		Sleep(200);
	}

	// testing output to make sure people are put into their corresponding floor lists
	/*cout << endl;
	for (Floor* eachFloor : floorList) {
		cout << "Floor: " << eachFloor->floorNum << ", numUp: " << eachFloor->numUp << ", numDown: " << eachFloor->numDown << endl;
		for (People* tempPerson : eachFloor->peopleList) {
			cout << "Initial floor: " << tempPerson->initialFloor << ", goal floor: " << tempPerson->goalFloor << endl;
		}
	}*/
	//cout << "Cycles completed. Total number of people in the building: " << peopleList.size() << endl;
	return 0;
}

// initiate the list of sequence when an elevator arrives at its destination floor
void Manager::elevatorArrived(Elevator* tempElevator) {
	int currentFloor = tempElevator->floor;

	//cout << "Holding the elevator at floor " << currentFloor << endl;
	tempElevator->canMove = false;

	//cout << "Changing speed to 0" << endl;
	tempElevator->speed = 0; // resting to let people out and in

	//cout << "Clearing elevator's internal button press for this floor" << endl;
	tempElevator->buttonsPressed[currentFloor - 1] = false;

	//cout << "Setting next random destination" << endl;
	tempElevator->nextStop = rand() % FLOORS + 1; // set a random next stop somewhere in the building
	while (tempElevator->nextStop == currentFloor) { // make sure destination is not its own floor
		tempElevator->nextStop = rand() % FLOORS + 1;
	}
	cout << "New destination " << tempElevator->nextStop << endl;

	//cout << "People get out of the elevator" << endl;
	vector<People*> remainingList = {}; // list of people remaining in the elevator after some exit
	for (People* tempPerson : tempElevator->peopleList) {
		if (tempPerson->goalFloor == currentFloor) { // if the person is to be removed, remove it from peopleList
			auto index = find(peopleList.begin(), peopleList.end(), tempPerson);
			if (index!=peopleList.end()) { // if tempPerson is indeed found in peopleList
				swap(*index, peopleList.back()); // swaps target element with last
				peopleList.pop_back(); // remove target element from list
			}
		}
		else { remainingList.push_back(tempPerson); } // else the person is not to be removed
	}
	tempElevator->peopleList = remainingList; // recalibrate the list
	generateNewRiders(tempElevator->numPeople - remainingList.size()); // generate new people in the building based on the number that left
	tempElevator->numPeople = remainingList.size(); // recalculate current capacity

	// move people from the current floor into elevator until floor empty or elevator full
	// then recalculate current capacity
	//cout << "People move from that floor's waitlist into the elevator regardless of direction" << endl;
	//cout << "Reduces direction calls accordingly and applies internal presses" << endl;
	vector<People*> tempWaitlist = floorList[tempElevator->floor - 1]->peopleList; // list of people waiting on that floor
	while (tempWaitlist.size() > 0) { // while there are people waiting on that floor
		if (tempElevator->numPeople < CAPACITY) { // if the elevator is not full
			tempElevator->peopleList.push_back(tempWaitlist[0]); // first person waiting walks into the elevator
			tempElevator->numPeople++;
			//cout << "Person moved into elevator" << endl;
			// if someone that wanted to go up got in the elevator, reduce floor's up call
			if (tempWaitlist[0]->goalFloor > tempWaitlist[0]->initialFloor) { floorList[tempElevator->floor - 1]->numUp--; /*cout << "Up Pressed" << endl;*/ }
			else { floorList[tempElevator->floor - 1]->numDown--; /*cout << "Down pressed" << endl;*/ }
			// apply newcomer's internal button press
			tempElevator->buttonsPressed[tempWaitlist[0]->goalFloor - 1] = true;
			//cout << "Internal button press applied" << endl;
			tempWaitlist.erase(tempWaitlist.begin()); // first person no longer waiting on that floor
			//cout << "Person removed from floor" << endl;
		}
		else {
			cout << "Elevator is full" << endl;
			break; // stops loading
		}
	}
	floorList[tempElevator->floor - 1]->peopleList = tempWaitlist; // reset the current waitlist
	//cout << "Reset floor's waitlist" << endl;

	//cout << "Allowing the elevator to move again" << endl;
	tempElevator->canMove = true;

	//cout << "Setting new speed and direction based on nextStop and call urgency" << endl;
	int countPresses = 0;
	if (tempElevator->nextStop > currentFloor) {  // if it will be going up
		tempElevator->direction = 1;
		for (int j = currentFloor; j < FLOORS; j++) { // sum all calls from floors above
			countPresses += floorList[j]->numUp + floorList[j]->numDown;
		}
	}
	else { // if it will be going down
		tempElevator->direction = -1;
		for (int j = 0; j < currentFloor; j++) { // sum all calls from floors below
			countPresses += floorList[j]->numUp + floorList[j]->numDown;
		}
	}
	tempElevator->nextSpeed(countPresses); // set new speed based on how many times it's called
	cout << "New speed is set to " << tempElevator->speed << endl;

	tempElevator->distanceToNextFloor = DIST_BTW_FLOORS;
	//cout << "Reset distance to next floor" << endl;

	cout << "People waiting on floor " << currentFloor << ": " << endl;
	for (int m = 0; m < tempWaitlist.size(); m++) {
		cout << "Person " << m << " on floor " << tempWaitlist[m]->initialFloor << " wants to go to floor " << tempWaitlist[m]->goalFloor << endl;
	}
	cout << "People in this elevator: " << endl;
	for (int m = 0; m < tempElevator->peopleList.size(); m++) {
		cout << "Person " << m << " on floor " << tempElevator->peopleList[m]->initialFloor << " wants to go to floor " << tempElevator->peopleList[m]->goalFloor << endl;
	}
	//cout << "Internal buttons pressed: " << endl;
	/*for (int m = 0; m < FLOORS; m++) {
		tempElevator->buttonsPressed[m] ? cout << "yes " : cout << "no ";
	}*/
}

// in-house tests of the contents of each list
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

// returns a vector containing the current position of all elevators
vector<float> Manager::getElevatorFloorNums() {
	vector<float> floorNums = {};
	for (Elevator* tempElevator : elevatorList) {
		floorNums.push_back(tempElevator->floor);
	}
	return floorNums;
}

// generate new people in the building based on the number that left the elevator
void Manager::generateNewRiders(int num) {
	for (int i = 0; i < num; i++) {
		People* tempPerson = new People();		// this way, peopleList adds a pointer to a heap item
		peopleList.push_back(tempPerson);		// adds a new default person
		floorList[tempPerson->initialFloor - 1]->peopleList.push_back(tempPerson); // add the person to their starting floor
		if (tempPerson->goalFloor > tempPerson->initialFloor) {
			floorList[tempPerson->initialFloor - 1]->numUp++; // if new person request to go up
		}
		else {
			floorList[tempPerson->initialFloor - 1]->numDown++; // if new person request to go down
		}
	}
}