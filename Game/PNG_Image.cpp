#include "PNG_Image.h"

PNG_Image::PNG_Image()
{
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
}

PNG_Image::PNG_Image(HMODULE hModule, int IpPngName)
{
	image = LoadPNG(hModule, MAKEINTRESOURCE(IpPngName));

	x = 0;
	y = 0;
	w = GetWidth();
	h = GetHeight();
}

PNG_Image::~PNG_Image()
{
	delete image;
	GdiplusShutdown(gdiplusToken);
}

Image * PNG_Image::LoadPNG(HMODULE hModule, LPCWSTR ResourceName)
{
	Image* image = NULL;
	IStream* pStream = NULL;

	HRSRC hResource = FindResource(hModule, ResourceName, L"PNG");

	if (CreateStreamOnHGlobal(NULL, TRUE, &pStream) == S_OK)
	{
		PVOID pResourceData = LockResource(LoadResource(hModule, hResource));
		DWORD imageSize = SizeofResource(hModule, hResource);
		DWORD dwReadWrite = 0;
		pStream->Write(pResourceData, imageSize, &dwReadWrite);
		image = Image::FromStream(pStream);
		pStream->Release();
	}

	return image;
}

void PNG_Image::LoadPNG(HMODULE hModule, int IpPngName)
{
	image = LoadPNG(hModule, MAKEINTRESOURCE(IpPngName));

	x = 0;
	y = 0;
	w = GetWidth();
	h = GetHeight();
}

Image* PNG_Image::GetImage()
{
	return image;
}

float PNG_Image::get_X()
{
	return x;
}

float PNG_Image::get_Y()
{
	return y;
}

float PNG_Image::get_W()
{
	return w;
}

float PNG_Image::get_H()
{
	return h;
}

int PNG_Image::GetWidth()
{
	return image->GetWidth();
}

int PNG_Image::GetHeight()
{
	return image->GetHeight();
}

void PNG_Image::set_X(float x)
{
	this->x = x;
}

void PNG_Image::set_Y(float y)
{
	this->y = y;
}

void PNG_Image::set_W(float w)
{
	this->w = w;
}

void PNG_Image::set_H(float h)
{
	this->h = h;
}

void PNG_Image::set_AllPoint(float x, float y, float w, float h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}
