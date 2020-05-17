//#pragma once
//
//#include <Windows.h>
//#include <d2d1.h>
//#include <dwrite.h>
//#include <cwchar>
//#include <stdio.h>
//
//class Graphics {
//	ID2D1Factory* factory;
//
//	IDWriteFactory* WriteFactory;
//	IDWriteTextFormat* TextFormat;
//
//	ID2D1HwndRenderTarget* renderTarget;
//	ID2D1SolidColorBrush* brush;
//
//public:
//	Graphics();
//	~Graphics();
//
//	bool Init(HWND windowHandle);
//
//	void BeginDraw() {
//		renderTarget->BeginDraw();
//	}
//	void EndDraw() {
//		renderTarget->EndDraw();
//	}
//	void ClearScreen(float r, float g, float b);
//
//	void DrawCircle(float x, float y, float radius, float r, float g, float b, float a);
//	void DrawRectangle(float w, float x, float y, float z, float r, float g, float b, float a);
//	void FillRectangle(float w, float x, float y, float z, float r, float g, float b, float a);
//
//	// void DrawTextW(const WCHAR* text, IDWriteTextFormat* textFormat, float w, float x, float y, float z, float r, float g, float b, float a);
//};