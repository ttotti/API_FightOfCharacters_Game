#include "Chirno.h"

Chirno::Chirno()
{
}

Chirno::Chirno(HINSTANCE g_hInst, HWND hWnd)
	:Layer(g_hInst, hWnd)
{
	Chirnoface = new PNG_Image;
	Chirnoface->LoadPNG(g_hInst, IDB_pCHIRNOFACE);

	for (int i = 0; i < MAX_Card; i++)
	{
		ChirnoCard[i] = new PNG_Image;

		ChirnoCard[i]->LoadPNG(g_hInst, IDB_pChirnoCard_1 + i);
	}
}

Chirno::~Chirno()
{
	delete Chirnoface;
	Chirnoface = NULL;

	for (int i = 0; i < MAX_Card; i++)
	{
		delete ChirnoCard[i];
		ChirnoCard[i] = NULL;
	}

	printf("Chirno Å¬·¡½º ¼Ò¸ê!\n");
}

void Chirno::init()
{
}

void Chirno::DrawBitmap()
{
}
