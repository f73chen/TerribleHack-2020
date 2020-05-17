#include "Graphics.h"
#include "ElevatorRender.h"
#include <vector>
using namespace std;

void ElevatorRender::drawShafts(Graphics* graphics) {
	// 2 Elevator Shafts - Height: 700
	// Shaft 1
	graphics->DrawRectangle( // Shaft 1
		400, 10, // top left x, y
		560, 710, // bottom right x, y
		0.5f, 0.5f, 0.5f, 0.5f
	);
	graphics->DrawRectangle( // floor 7
		400, 10,
		560, 110,
		0.5f, 0.5f, 0.5f, 0.5f
	);
	graphics->DrawRectangle( // floor 6
		400, 110,
		560, 210,
		0.5f, 0.5f, 0.5f, 0.5f
	);
	graphics->DrawRectangle( // floor 5
		400, 210,
		560, 310,
		0.5f, 0.5f, 0.5f, 0.5f
	);
	graphics->DrawRectangle( // floor 4
		400, 310,
		560, 410,
		0.5f, 0.5f, 0.5f, 0.5f
	);
	graphics->DrawRectangle( // floor 3
		400, 410,
		560, 510,
		0.5f, 0.5f, 0.5f, 0.5f
	);
	graphics->DrawRectangle( // floor 2
		400, 510,
		560, 610,
		0.5f, 0.5f, 0.5f, 0.5f
	);
	graphics->DrawRectangle( // floor 1
		400, 610,
		560, 710,
		0.5f, 0.5f, 0.5f, 0.5f
	);
	// Shaft 2
	graphics->DrawRectangle( // Shaft 2
		720, 10, // top left x, y
		880, 710, // bottom right x, y
		0.5f, 0.5f, 0.5f, 0.5f
	);
	graphics->DrawRectangle( // floor 7
		720, 10,
		880, 110,
		0.5f, 0.5f, 0.5f, 0.5f
	);
	graphics->DrawRectangle( // floor 6
		720, 110,
		880, 210,
		0.5f, 0.5f, 0.5f, 0.5f
	);
	graphics->DrawRectangle( // floor 5
		720, 210,
		880, 310,
		0.5f, 0.5f, 0.5f, 0.5f
	);
	graphics->DrawRectangle( // floor 4
		720, 310,
		880, 410,
		0.5f, 0.5f, 0.5f, 0.5f
	);
	graphics->DrawRectangle( // floor 3
		720, 410,
		880, 510,
		0.5f, 0.5f, 0.5f, 0.5f
	);
	graphics->DrawRectangle( // floor 2
		720, 510,
		880, 610,
		0.5f, 0.5f, 0.5f, 0.5f
	);
	graphics->DrawRectangle( // floor 1
		720, 610,
		880, 710,
		0.5f, 0.5f, 0.5f, 0.5f
	);
}

// 2 Elevators - Width: 120, Height: 90
void ElevatorRender::drawElevators(vector<float> floorNum, Graphics* graphics) { // inputs: current floor numbers
	graphics->DrawRectangle( // Elevator 1
		400+20, 710-floorNum[0]*100+10, // top left x, y
		560-20, 710-floorNum[0]*100+100, // bottom right x, y
		0.0f, 0.0f, 1.0f, 0.8f
	);
	graphics->DrawRectangle( // Elevator 2
		720+20, 710-floorNum[1]*100+10, // top left x, y
		800-20, 710-floorNum[1]*100+100, // bottom right x, y
		0.0f, 0.0f, 1.0f, 0.8f
	);
}

// Waiting Area
void ElevatorRender::drawWaitingFloor(float floor, Graphics* graphics) { // input: waiting floor 
	// Waiting Floor - Height: 100
	graphics->DrawRectangle(
		300, 710 - floor * 100, // top left x, y
		660, 710 - floor * 100 + 100, // bottom right x, y
		0.5f, 0.5f, 0.5f, 0.5f
	);

	// Left and Right Doors - Width: 120, Height: 90
	// Left Doors	
	graphics->DrawRectangle(
		400 + 20, 710 - floor * 100 + 10, // top left x, y
		400 + 80, 710 - floor * 100 + 100, // bottom right x, y
		0.5f, 0.5f, 0.5f, 0.5f
	);
	graphics->DrawRectangle(
		400 + 80, 710 - floor * 100 + 10, // top left x, y
		560 - 20, 710 - floor * 100 + 100, // bottom right x, y
		0.5f, 0.5f, 0.5f, 0.5f
	);
	// Right Doors
	graphics->DrawRectangle(
		720 + 20, 710 - floor * 100 + 10, // top left x, y
		720 + 80, 710 - floor * 100 + 100, // bottom right x, y
		0.5f, 0.5f, 0.5f, 0.5f
	);
	graphics->DrawRectangle(
		720 + 80, 710 - floor * 100 + 10, // top left x, y
		880 - 20, 710 - floor * 100 + 100, // bottom right x, y
		0.5f, 0.5f, 0.5f, 0.5f
	);

	// Up and Down Buttons - Radius: 20
	graphics->DrawCircle( // Up
		(720 + 560) / 2, 710 - floor * 100 + 25, // x, y
		20, // radius
		0.5f, 0.5f, 0.5f, 0.5f
	);
	graphics->FillCircle(
		(720 + 560) / 2, 710 - floor * 100 + 25, // x, y
		20, // radius
		0.5f, 0.5f, 0.5f, 0.5f
	);
	graphics->DrawCircle( // Down
		(720 + 560) / 2, 710 - floor * 100 + 75, // x, y
		20, // radius
		0.5f, 0.5f, 0.5f, 0.5f
	);
	graphics->FillCircle(
		(720 + 560) / 2, 710 - floor * 100 + 75, // x, y
		20, // radius
		0.5f, 0.5f, 0.5f, 0.5f
	);
}