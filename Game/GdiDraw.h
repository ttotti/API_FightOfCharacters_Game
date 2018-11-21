#pragma once

#include <Windows.h>
#include <gdiplus.h>
#include <stdio.h>
#include <wingdi.h>

using namespace Gdiplus;

class GDIplus
{
public:
	ULONG_PTR gdiplusToken;
	GdiplusStartupInput gdiplusStartupInput;

	Image* image;

	HWND hWnd;

public:
	GDIplus();
	GDIplus(HWND hWnd);
	~GDIplus();

	void setImage(HWND hWnd, const WCHAR* Filename);
	void DrawImage(int x, int y, const WCHAR* Filename);
};