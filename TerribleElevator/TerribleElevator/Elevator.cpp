#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "Elevator.hpp"
using namespace std;

// default constructor
Elevator::Elevator() :floor(2), speed(6), canMove(true), nextStop(1), peopleList({}), distanceToNextFloor(DIST_BTW_FLOORS), numPeople(0) {
	vector<bool> nbuttonsPressed(FLOORS, false);
	buttonsPressed = nbuttonsPressed; // assumes that no buttons are pressed
	// NOTE: nextStop must not be the same as floor
	direction = nextStop > floor ? 1 : -1;
}

// parameterized constructor
Elevator::Elevator(int nfloor, int nspeed, bool ncanMove, vector<bool> nbuttonsPressed, int nnextStop, vector<People*> npeopleList) :
	floor(nfloor), speed(nspeed), canMove(ncanMove), buttonsPressed(nbuttonsPressed),
	nextStop(nnextStop), peopleList(npeopleList), distanceToNextFloor(DIST_BTW_FLOORS) {
	numPeople = peopleList.size();
	direction = nextStop > floor ? 1 : -1;
}

// PURPOSE: checks whether the car can move to the next space specified
bool Elevator::validMove() {
	// if manager tells the car to not move
	if (!canMove) { cout << "Can't move" << endl; return false; }

	// if already at the top floor and going up
	if (floor == FLOORS && direction > 0) { cout << "At ceiling" << endl; return false; }

	// if already at the bottom floor and going down
	if (floor == 0 && direction < 0) { cout << "At ground" << endl; return false; }
	
	// if all goes well and move is valid
	return true;
}

// PURPOSE: checks current floor, direction, stopping distance and next floor to determine what speed it should travel at
// NOTE: when arriving at the destination floor, speed should be less than accel (either 0 or accel/2)
void Elevator::nextSpeed(int numCalls) {
	if (!validMove()) { speed = 0; cout << "Invalid move" << endl; return; }	// not allowed to move
	int boost = numCalls / FLOORS;				// integer division of the total number of floors
	speed = MAX_SPEED + boost;		// able to have a higher topspeed
}