#pragma once

class Gui {
public:
	void Render(Graphics* gfx, HWND hwnd, int currFloor);
	bool Check(int x, int y);
};