//#include <Windows.h>
//#include <d2d1.h>
//#include "Graphics.h"
//#include "Manager.hpp"
//#include "Floor.hpp"
//#include "Elevator.h"
//#include "People.hpp"
//#include "Graphics.h"
//
//Graphics* graphics;
//LRESULT CALLBACK WindowProc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam) {
//	if (uMsg == WM_DESTROY) {
//		PostQuitMessage(0);
//		return 0;
//	}
//
//	if (uMsg == WM_PAINT) {
//		graphics->BeginDraw();
//
//		graphics->ClearScreen(0.0f, 0.0f, 0.5f);
//
//		// Draw menu wrap
//		graphics->DrawRectangle(
//			290, 600, // top left x, y
//			990, 120, // bottom right x, y
//			0.5f,
//			0.5f,
//			0.5f,
//			0.5f
//		);
//		graphics->FillRectangle(
//			290, 600, // top left x, y
//			990, 120, // bottom right x, y
//			0.5f,
//			0.5f,
//			0.5f,
//			0.5f
//		);
//
//		// Draw floor number display screen
//		graphics->DrawRectangle(
//			325, 580, // top left x, y
//			955, 480, // bottom right x, y
//			0.5f,
//			0.5f,
//			0.5f,
//			0.5f
//		);
//
//		// Draw floor number (in display sceen)
//		// graphics->DrawTextW(
//
//		// );
//
//		// Draw floor buttons
//		graphics->DrawCircle( // Floor 7
//			325 + 420 + 105, 360 + 60,// x,y
//			30, // radius
//			0.5f,
//			0.5f,
//			0.5f,
//			0.5f
//		);
//		graphics->DrawCircle( // Floor 6
//			325 + 210 + 105, 360 + 60,// x,y
//			30, // radius
//			0.5f,
//			0.5f,
//			0.5f,
//			0.5f
//		);
//		graphics->DrawCircle( // Floor 5
//			325 + 105, 360 + 60,// x,y
//			30, // radius
//			0.5f,
//			0.5f,
//			0.5f,
//			0.5f
//		);
//		graphics->DrawCircle( // Floor 4
//			290 + 525 + (175 / 2), 240 + 60,// x,y
//			30, // radius
//			0.5f,
//			0.5f,
//			0.5f,
//			0.5f
//		);
//		graphics->DrawCircle( // Floor 3
//			290 + 350 + (175 / 2), 240 + 60,// x,y
//			30, // radius
//			0.5f,
//			0.5f,
//			0.5f,
//			0.5f
//		);
//		graphics->DrawCircle( // Floor 2
//			290 + 175 + (175 / 2), 240 + 60,// x,y
//			30, // radius
//			0.5f,
//			0.5f,
//			0.5f,
//			0.5f
//		);
//		graphics->DrawCircle( // Floor 1
//			290 + (175 / 2), 240 + 60,// x,y
//			30, // radius
//			0.5f,
//			0.5f,
//			0.5f,
//			0.5f
//		);
//
//		// Draw open and close buttons
//		// graphics->DrawRectangle(
//
//		// );
//
//		graphics->EndDraw();
//	}
//
//	DefWindowProc(hwnd, uMsg, wParam, lParam);
//}
//
//int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
//	WNDCLASSEX windowclass;
//	ZeroMemory(&windowclass, sizeof(WNDCLASSEX));
//	windowclass.cbSize = sizeof(WNDCLASSEX);
//	windowclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
//	windowclass.hInstance = hInstance;
//	windowclass.lpfnWndProc = WindowProc;
//	windowclass.lpszClassName = L"MainWindow";
//	windowclass.style = CS_HREDRAW | CS_VREDRAW;
//
//	RegisterClassEx(&windowclass);
//
//	RECT rect = { 0, 0, 1280, 720 };
//	AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, false, WS_EX_OVERLAPPEDWINDOW);
//
//	HWND windowHandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"MainWindow", L"TerribleElevator", WS_OVERLAPPEDWINDOW, 100, 100,
//		rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, 0);
//
//	if (!windowHandle) return -1;
//
//	graphics = new Graphics();
//
//	if (!graphics->Init(windowHandle)) {
//		delete graphics;
//		return -1;
//	}
//
//	ShowWindow(windowHandle, nCmdShow);
//
//	MSG message;
//	while (GetMessage(&message, NULL, 0, 0)) {
//		DispatchMessage(&message);
//	}
//
//	return 0;
//}
