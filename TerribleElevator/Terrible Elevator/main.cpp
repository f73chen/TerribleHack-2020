#include <Windows.h>
#include <d2d1.h>
#include <iostream>
#include "Graphics.h"
#include "gui.h"
#include "ElevatorRender.h"
#include "User.hpp"
#include "Manager.hpp"

Graphics* graphics;
Gui gui;
ElevatorRender elevatorrender;

LRESULT CALLBACK WindowProc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam) {

	if (uMsg == WM_DESTROY) {
		PostQuitMessage(0);
		return 0;
	}

	DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
	WNDCLASSEX windowclass;
	ZeroMemory(&windowclass, sizeof(WNDCLASSEX));
	windowclass.cbSize = sizeof(WNDCLASSEX);
	windowclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	windowclass.hInstance = hInstance;
	windowclass.lpfnWndProc = WindowProc;
	windowclass.lpszClassName = L"MainWindow";
	windowclass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClassEx(&windowclass);

	RECT rect = { 0, 0, 1280, 720 };
	AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, false, WS_EX_OVERLAPPEDWINDOW);

	HWND windowHandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"MainWindow", L"TerribleElevator", WS_OVERLAPPED | WS_SYSMENU, 100, 100,
		rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, 0);

	if (!windowHandle) return -1;

	graphics = new Graphics();

	if (!graphics->Init(windowHandle)) {
		delete graphics;
		return -1;
	}

	ShowWindow(windowHandle, nCmdShow);

	bool guiStatus = false;
	int currFloor = 1;
	bool click = false;

	POINT cursorPos;

	MSG message;
	message.message = WM_NULL;

	while (message.message != WM_QUIT) {
		if (PeekMessageW(&message, NULL, 0, 0, PM_REMOVE)) {
			DispatchMessage(&message);
		}
		else {
			// Update
			if (message.message == WM_LBUTTONDOWN && click == false) {
				click = true;
				OutputDebugString(L"Work\n");
				GetCursorPos(&cursorPos);
				ScreenToClient(windowHandle, &cursorPos);
				int x = cursorPos.x;
				int y = cursorPos.y;

				if (guiStatus) {
					if (gui.Check(x, y)) {
						OutputDebugString(L"True\n");
					}
					else {
						OutputDebugString(L"False\n");
					}
				}
			}
			else if (message.message = WM_LBUTTONUP && click == true) {
				click = false;
			}

			// Render
			graphics->BeginDraw();

			graphics->ClearScreen(1.0f, 1.0f, 0.8f);

			// Check if GUI is true
			if (guiStatus) {
				gui.Render(graphics, windowHandle, currFloor);
			}
			else {
				elevatorrender.drawShafts(graphics);
				elevatorrender.drawElevators(Manager::getElevatorFloorNums(), graphics);
				elevatorrender.drawWaitingFloor(User::getCurrentFloor(), graphics);
			}

			graphics->EndDraw();
		}
	}	
	return 0;
}
