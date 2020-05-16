#include "Graphics.h"

Graphics::Graphics() {
	factory = NULL;
	renderTarget = NULL;
	brush = NULL;
}

Graphics::~Graphics() {
	if (factory) factory->Release();
	if (renderTarget) renderTarget->Release();
	if (brush) brush->Release();
}

bool Graphics::Init(HWND windowHandle) {
	HRESULT res = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);
	if (res != S_OK) return false;

	RECT rect;
	GetClientRect(windowHandle, &rect);

	res = factory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(), 
		D2D1::HwndRenderTargetProperties(
			windowHandle, D2D1::SizeU(rect.right, rect.bottom)), 
		&renderTarget);

	if (res != S_OK) return false;

	res = renderTarget->CreateSolidColorBrush(D2D1::ColorF(0, 0, 0, 0), &brush);
	if (res != S_OK) return false;

	HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);
	if (SUCCEEDED(hr)) {
		hr = DWriteCreateFactory(
			DWRITE_FACTORY_TYPE_SHARED,
			__uuidof(IDWriteFactory),
			reinterpret_cast<IUnknown**>(&WriteFactory)
		);
	}

	return true;
}
void Graphics::ClearScreen(float r, float g, float b) {
	renderTarget->Clear(D2D1::ColorF(r, g, b));
}

void Graphics::DrawCircle(float x, float y, float radius, float r, float g, float b, float a) {
	brush->SetColor(D2D1::ColorF(r, g, b, a));
	renderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius), brush, 3.0f);
}

void Graphics::DrawRectangle(float w, float x, float y, float z, float r, float g, float b, float a) {
	brush->SetColor(D2D1::ColorF(r, g, b, a));
	renderTarget->DrawRectangle(D2D1::RectF(w, x, y, z), brush, 3.0f);
}

void Graphics::FillRectangle(float w, float x, float y, float z, float r, float g, float b, float a) {
	brush->SetColor(D2D1::ColorF(r, g, b, a));
	renderTarget->FillRectangle(D2D1::RectF(w, x, y, z), brush);
}

void Graphics::DrawTextW(const wchar_t* text, IDWriteTextFormat* textFormat, float w, float x, float y, float z, float r, float g, float b, float a) {
	brush->SetColor(D2D1::ColorF(r, g, b, a));
	renderTarget->DrawTextW(text, (UINT32) wsclen(text), );
}
