#include <Windows.h>
#include <d2d1.h>
#include "Graphics.h"

Graphics* graphics; 

LRESULT CALLBACK WindowProc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam) {
	if(uMsg == WM_DESTROY) {
		PostQuitMessage(0);
		return 0;
	}

	if(uMsg == WM_PAINT) {
		graphics->BeginDraw();

		graphics->ClearScreen(0.0f, 0.0f, 0.5f);

		graphics->DrawCircle(550, 360, 50,
			0.5f,
			0.5f,
			0.5f,
			0.5f);

		graphics->DrawCircle(700, 360, 50,
			0.5f,
			0.5f,
			0.5f,
			0.5f);

		graphics->EndDraw();
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

	HWND windowHandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"MainWindow", L"TerribleElevator", WS_OVERLAPPEDWINDOW, 100, 100, 
		rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, 0);

	if (!windowHandle) return -1;

	graphics = new Graphics();

	if(!graphics->Init(windowHandle)) {
		delete graphics;
		return -1;
	}

	ShowWindow(windowHandle, nCmdShow);

	MSG message;
	while (GetMessage(&message, NULL, 0, 0)) {
		DispatchMessage(&message);
	}
		
	return 0;
}
