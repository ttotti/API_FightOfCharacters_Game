#include "Chirno.h"

Chirno::Chirno()
{
}

Chirno::Chirno(HINSTANCE g_hInst, HWND hWnd)
	:Layer(g_hInst, hWnd)
{
	ChirnoCard2 = new PNG_Image;
	ChirnoCard2->LoadPNG(g_hInst, IDB_pChirnoCard_1);

	for (int i = 0; i < MAX_Card; i++)
	{
		ChirnoCard[i] = new PNG_Image;

		ChirnoCard[i]->LoadPNG(g_hInst, IDB_pChirnoCard_1 + i);
	}
}

Chirno::~Chirno()
{
}

void Chirno::init()
{
}

void Chirno::DrawBitmap()
{
	ChirnoCard2->set_X(300);
	this->Draw_PNGImage(ChirnoCard2);

	int x = 0;

	for (int i = 0; i < MAX_Card; i++)
	{
		ChirnoCard[i]->set_X(100 + x);
		this->Draw_PNGImage(ChirnoCard[i]);
		x += 50;
	}
}
