#pragma once
#include <vector>
using namespace std;

class ElevatorRender {
public:
	void drawShafts(Graphics* gfx);
	void drawElevators(int floorNum1, int floorNum2, Graphics* gfx);
	void drawWaitingFloor(int floor, Graphics* gfx);
};