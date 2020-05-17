#include "Graphics.h"
#include "gui.h"
#include <string>
#include <iostream>
using namespace std;


void Gui::Render(Graphics* gfx, HWND hwnd, int currFloor) {
	// Draw menu wrap
	gfx->DrawRectangle(
		250, 100, // top left x, y
		1030, 620, // bottom right x, y
		0.5f, 0.5f, 0.5f, 0.5f
	);

	gfx->FillRectangle(
		250, 100, // top left x, y
		1030, 620, // bottom right x, y
		1.0f, 1.0f, 1.0f, 0.8f
	);

	// Draw floor number display screen
	gfx->FillRectangle(
		330, 140,
		950, 240,
		0.76f, 0.76f, 0.76f, 0.8f
	);
	// Draw floor number (in display sceen)
	gfx->WriteText(
		hwnd, L"Floor",
		330, 140,
		950, 240
	);

	// Draw floor buttons
	gfx->DrawCircle( // Floor 7
		325 + 420 + 105, 120 + 120 + 60, // x, y
		40, // radius
		0.5f, 0.5f, 0.5f, 0.5f
	);
	gfx->FillCircle( // Floor 7
		325 + 420 + 105, 120 + 120 + 60, // x, y
		40, // radius
		0.0f, 0.0f, 1.0f, 0.8f 
	);
	gfx->WriteText(
		hwnd, L"7",
		850+30, 300-30,
		850-30, 300+30
	);

	gfx->DrawCircle( // Floor 6
		325 + 210 + 105, 120 + 120 + 60, // x, y
		40, // radius
		0.5f, 0.5f, 0.5f, 0.5f
	);
	gfx->FillCircle( // Floor 6
		325 + 210 + 105, 120 + 120 + 60, // x, y
		40, // radius
		0.0f, 0.0f, 1.0f, 0.8f
	);
	gfx->WriteText(
		hwnd, L"6",
		640+30, 300-30,
		640-30, 300+30
	);

	gfx->DrawCircle( // Floor 5
		325 + 105, 120 + 120 + 60, // x, y
		40, // radius
		0.5f, 0.5f, 0.5f, 0.5f
	);
	gfx->FillCircle( // Floor 5
		325 + 105, 120 + 120 + 60, // x, y
		40, // radius
		0.0f, 0.0f, 1.0f, 0.8f
	);
	gfx->WriteText(
		hwnd, L"5",
		430+30, 300-30,
		430-30, 300+30
	);

	gfx->DrawCircle( // Floor 4
		290 + 525 + (175 / 2), 120 + 240 + 60, // x, y
		40, // radius
		0.5f, 0.5f, 0.5f, 0.5f
	);
	gfx->FillCircle( // Floor 4
		290 + 525 + (175 / 2), 120 + 240 + 60, // x, y
		40, // radius
		0.0f, 0.0f, 1.0f, 0.8f
	);
	gfx->WriteText(
		hwnd, L"4",
		(1805/2)+30, 420-30,
		(1805/2)+30, 420+30
	);

	gfx->DrawCircle( // Floor 3
		290 + 350 + (175 / 2), 120 + 240 + 60, // x, y
		40, // radius
		0.5f, 0.5f, 0.5f, 0.5f
	);
	gfx->FillCircle( // Floor 3
		290 + 350 + (175 / 2), 120 + 240 + 60, // x, y
		40, // radius
		0.0f, 0.0f, 1.0f, 0.8f
	);
	gfx->WriteText(
		hwnd, L"3",
		(1455/2)+30, 420-30,
		(1455/2)+30, 420+30
	);

	gfx->DrawCircle( // Floor 2
		290 + 175 + (175 / 2), 120 + 240 + 60, // x, y
		40, // radius
		0.5f, 0.5f, 0.5f, 0.5f
	);
	gfx->FillCircle( // Floor 2
		290 + 175 + (175 / 2), 120 + 240 + 60, // x, y
		40, // radius
		0.0f, 0.0f, 1.0f, 0.8f
	);
	gfx->WriteText(
		hwnd, L"2",
		(1105/2)+30, 420-30,
		(1105/2)+30, 420+30
	);

	gfx->DrawCircle( // Floor 1
		290 + (175 / 2), 120 + 240 + 60, // x, y
		40, // radius
		0.5f, 0.5f, 0.5f, 0.5f
	);
	gfx->FillCircle( // Floor 1
		290 + (175 / 2), 120 + 240 + 60, // x, y
		40, // radius
		0.0f, 0.0f, 1.0f, 0.8f
	);
	gfx->WriteText(
		hwnd, L"1",
		(755/2)+30, 420-30,
		(755/2)+30, 420+30
	);

	// Draw open and close buttons
	gfx->DrawRectangle( // Open button
		290 + 175 + (175 / 2) - 40, 100 + 360 + 40, // top left x,y
		290 + 175 + (175 / 2) + 40, 100 + 360 + 120, // bottom right x, y
		0.5f, 0.5f, 0.5f, 0.5f
	);
	gfx->FillRectangle( // Open button
		290 + 175 + (175 / 2) - 40, 100 + 360 + 40, // top left x,y
		290 + 175 + (175 / 2) + 40, 100 + 360 + 120, // bottom right x, y
		0.69f, 0.02f, 0.0f, 0.8f
	);

	gfx->DrawRectangle( // Close button
		290 + 350 + (175 / 2) - 40, 100 + 360 + 40, // top left x,y
		290 + 350 + (175 / 2) + 40, 100 + 360 + 120, // bottom right x, y
		0.5f, 0.5f, 0.5f, 0.5f
	);
	gfx->FillRectangle( // Close button
		290 + 350 + (175 / 2) - 40, 100 + 360 + 40, // top left x,y
		290 + 350 + (175 / 2) + 40, 100 + 360 + 120, // bottom right x, y
		0.69f, 0.02f, 0.0f, 0.8f
	);
}

bool Gui::Check(int x, int y) {
	if (x >= 1025 / 2 && x <= 1185 / 2 && y >= 500 && y <= 580) {
		OutputDebugString(L"Open Button");
		return true;
	}
	else if (x >= 1375/2 && x <= 1535/2 && y >= 500 && y <= 580) {
		OutputDebugString(L"Close Button");
		return true;
	}
	else if (pow((x - 377.5), 2) + pow((y - 420.0), 2) <= pow(40,2)) {
		OutputDebugString(L"Level 1");
	}
	else if (pow((x - 552.5), 2) + pow((y - 420.0), 2) <= pow(40, 2)) {
		OutputDebugString(L"Level 2");
	}
	else if (pow((x - 727.5), 2) + pow((y - 420.0), 2) <= pow(40, 2)) {
		OutputDebugString(L"Level 3");
	}
	else if (pow((x - 902.5), 2) + pow((y - 420.0), 2) <= pow(40, 2)) {
		OutputDebugString(L"Level 4");
	}
	else if (pow((x - 430.0), 2) + pow((y - 300.0), 2) <= pow(40, 2)) {
		OutputDebugString(L"Level 5");
	}
	else if (pow((x - 640.0), 2) + pow((y - 300.0), 2) <= pow(40, 2)) {
		OutputDebugString(L"Level 6");
	}
	else if (pow((x - 850.0), 2) + pow((y - 300.0), 2) <= pow(40, 2)) {
		OutputDebugString(L"Level 7");
	}
	else {
		return false;
	}
}