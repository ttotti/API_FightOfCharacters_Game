#include "GameStart.h"

GameStart::GameStart()
{
}

GameStart::GameStart(HINSTANCE g_hInst, HWND hWnd)
	:Layer(hWnd)
{
	gamemap = new gBitmap;

	gamemap->SetBitmap(hWnd, g_hInst, IDB_MAP);
}

GameStart::~GameStart()
{
	delete gamemap;

	gamemap = NULL;
}

void GameStart::DrawBitmap()
{
	gamemap->set_AllPoint(0, 0, WIN_WIGHT, WIN_HEIGHT);
	this->Draw_BitBlt(gamemap);



	this->Draw();
}
