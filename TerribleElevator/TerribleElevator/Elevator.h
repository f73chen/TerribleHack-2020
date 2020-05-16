#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;

class Elevator {
private:
	int position;	// which floor it's on
	int direction;	// -1 down, 0 stationary, 1 up
	bool canMove;	// whether manager knows the door is closed and elevator can move again
	vector<bool> buttonsPressed;	// vector of buttons, size is number of floors, 1 is pressed 0 is not pressed
	int nextStop;	// sent by manager: either the next button pressed or the next floor with someone waiting
	int FLOORS;		// total number of floors
	int CAPACITY;	// max capacity of the carriage
	int numPeople;	// number of people currently in the elevator
public:
	// constructors
	Elevator() :position(1), direction(0), canMove(false), buttonsPressed({false}), nextStop(1), FLOORS(1), CAPACITY(0), numPeople(0) {}
	Elevator(int nposition, int ndirection, bool ncanMove, vector<bool> nbuttonsPressed, int nnextStop, int nFLOORS, int nCAPACITY, int nnumPeople) :
		position(nposition), direction(ndirection), canMove(ncanMove), buttonsPressed(nbuttonsPressed), nextStop(nnextStop), FLOORS(nFLOORS), CAPACITY(nCAPACITY), numPeople(nnumPeople) {}


};