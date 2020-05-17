#pragma once
#include <vector>
using namespace std;

class ElevatorRender {
public:
	void drawShafts(Graphics* gfx);
	void drawElevators(vector<float> floorNum, Graphics* gfx);
	void drawWaitingFloor(int floor, Graphics* gfx);
};