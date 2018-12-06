#pragma once

//#pragma comment(lib,"Gdiplus.lib")

#include <Windows.h>
#include <stdio.h>
#include <gdiplus.h>

using namespace Gdiplus;

class PNG_Image
{
private:
	ULONG_PTR gdiplusToken;

	GdiplusStartupInput gdiplusStartupInput;
	
	Image* image;

private:
	float x, y, w, h;
	int bmWidth, bmHeight;

public:
	float get_X();
	float get_Y();
	float get_W();
	float get_H();

	int GetWidth();
	int GetHeight();

	void set_X(float x);
	void set_Y(float y);
	void set_W(float w);
	void set_H(float h);
	void set_AllPoint(float x, float y, float w, float h);

public:
	PNG_Image();
	PNG_Image(HMODULE hModule, int IpPngName);
	~PNG_Image();

	Image* LoadPNG(HMODULE hModule, LPCWSTR ResourceName);
	void LoadPNG(HMODULE hModule, int IpPngName);

	Image* GetImage();
};