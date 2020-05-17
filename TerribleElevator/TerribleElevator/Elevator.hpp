#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>
#include "People.hpp"
using namespace std;

class Elevator {
private:
	int floor;		// which floor it's on
	int speed;		// speed of travel
	int direction;	// direction of travel: -1 for down, 1 for up, 0 for stopped
	bool canMove;	// whether manager knows the door is closed and elevator can move again
	vector<bool> buttonsPressed;	// vector of buttons, size is number of floors, 1 is pressed 0 is not pressed
	int nextStop;	// sent by manager: either the next button pressed or the next floor with someone waiting, or the bottom or top floor
	int stoppingDistance;			// number of floors it takes for the elevator to go from full speed to stopped, if don't have this much room then will travel at 1/D speed
	vector<People*> peopleList;		// list of people riding that elevator
	int numPeople;					// number of people currently in the elevator
	int distanceToNextFloor;		// number of movement units needed to arrive at the next floor, whether stopping or not

public:
	// default constructor
	Elevator();

	// constructor with parameters
	Elevator(int nfloor, int nspeed, int ndirection, bool ncanMove, vector<bool> nbuttonsPressed, int nnextStop, int nstoppingDistance, vector<People*> npeopleList);

	// returns whether adding more people would not overload it
	bool withinCapacity(int additional) { return peopleList.size() + additional <= CAPACITY; }

	// PURPOSE: checks the position, direction, buttons pressed, and nextStop to determine whether it moves at 
	// INPUT: nnextStop given by the manager, tells where the next stop along the path someone pressed a button
	// INPUT: numCalls is the number of times the people waiting have pressed the up/down buttons
	void move(int numCalls);

	// PURPOSE: checks whether the car can move to the next space specified
	bool validMove();

	// PURPOSE: checks current floor, direction, stopping distance and next floor to determine what speed it should travel at
	// NOTE: when arriving at the destination floor, speed should be less than accel (either 0 or accel/2)
	// INPUT: numCalls is the number of times the people waiting have pressed the up/down buttons
	int nextSpeed(int numCalls);

	// PURPOSE: add an "additional" number of people into the elevator
	// OUTPUT: int is the number of people that couldn't make it in
	int enter(int additional);

	// PURPOSE: remove a "less" number of people from the elevator
	void leave(int left);

	// PURPOSE: add a list of buttons that the newly added people will press
	void pressButton(vector<int> floorNums);

	// PURPOSE: arrived at a certain floor, have to clear info about button
	void arrive();

	friend class Manager;	// Manager will be able to access private variables
};
#endif