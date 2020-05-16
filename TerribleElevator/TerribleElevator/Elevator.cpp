#include "Elevator.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
using namespace std;

// PURPOSE: checks the position, direction, buttons pressed, and nextStop to determine whether it moves at 
// INPUT: nnextStop given by the manager, tells where the next stop along the path someone pressed a button
void Elevator::move(int numCalls) {
	if (validMove()) {
		speed = nextSpeed(numCalls); // calculates how fast to travel next
		// NOTE: directX should use the speed information to know how fast to animate movement
		floor += direction; // if direction positive then go up, else stay put or go down
	}
	else {
		cout << "Error: invalid move.\nFloor: " << floor << ", direction: " << direction << ", speed: " << speed << endl;
	}
}

// PURPOSE: checks whether the car can move to the next space specified
bool Elevator::validMove() {
	// if manager tells the car to not move
	if (!canMove) { return false; }

	// if already at the top floor and going up
	if (floor == FLOORS && direction > 0) { return false; }

	// if already at the bottom floor and going down
	if (floor == 0 && direction < 0) { return false; }
}

// PURPOSE: checks current floor, direction, stopping distance and next floor to determine what speed it should travel at
// NOTE: when arriving at the destination floor, speed should be less than accel (either 0 or accel/2)
int Elevator::nextSpeed(int numCalls) {
	// if move is invalid, it should be stopped
	int boost = numCalls / FLOORS;				// integer division of the total number of floors
	int boostedStop = stoppingDistance;			// able to stop faster
	if (stoppingDistance - boost >= 1) { stoppingDistance -= boost; }
	else { stoppingDistance = 1; }
	int boostedSpeed = MAX_SPEED + boost;		// able to have a higher topspeed

	if (!validMove()) { return -1; }
	int absDist = abs(floor - nextStop);		// absolute distance between current position and target
	int accel = boostedSpeed / boostedStop;	// how much it can accelerate and decelerate at each floor

	// if remaining distance is more than stopping distance
	if (absDist > boostedStop) {
		speed += accel;	// speed up by one floor's worth of acceleration
		if (speed >= boostedSpeed) { // if over the speed limit set it back to the limit
			speed = boostedSpeed;
		}
	}
	else { // else within range of stopping, might have to slow down
		if (speed == 0) { // if at rest, must accelerate a bit to move
			if (absDist > boostedStop / 2) { // if have plenty of room
				speed += accel; // then acceleration; plan to decelerate at the next floor
			}
			else { // if too close to properly accelerate, do partial
				speed += accel / 2;
			}
		}
		else if (speed == boostedSpeed) { // if starting at max speed, then must slow down
			speed -= accel;
		}
		else { // if speed is not 0 but not max either
			if (speed - (absDist - 2) * accel <= 0) { //if have plenty of room to keep accelerating
				speed += accel;
			}
			else { //if too close, must slow down
				speed -= accel;
			}
		}
	}
	return 0; // move was accepted
}

// PURPOSE: add an "additional" number of people into the elevator
// OUTPUT: int is the number of people that couldn't make it in
int Elevator::enter(int additional) {
	if (numPeople + additional <= CAPACITY) { // everyone can fit
		numPeople += additional;
		return 0;
	}
	else { // some people are left behind on that floor
		additional += (numPeople - CAPACITY);
		numPeople = CAPACITY;
		return additional;
	}
}

// PURPOSE: remove a "less" number of people from the elevator
void Elevator::leave(int left) {
	if (numPeople < left) {
		cout << "Error: more people left than are in the elevator.\nFloor: " << floor << ", left: " << left << endl;
		return;
	}
	else {
		numPeople -= left;
	}
}

// PURPOSE: add a list of buttons that the newly added people will press
void Elevator::pressButton(vector<int> floorNums) {
	for (int i = 0; i < floorNums.size(); i++) { // iterates through the list of buttons pressed
		buttonsPressed[floorNums[i]] = 1; // set status to pressed
	}
	buttonsPressed[floor] = 0; // can't press the button for the floor you're already on
}

// PURPOSE: arrived at a certain floor, have to clear info about button
void Elevator::arrive() {
	speed = 0; //resets travel speed
	buttonsPressed[floor] = 0; // removes current floor from list of buttons
}