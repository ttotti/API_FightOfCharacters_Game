#include "GameStartScene.h"

GameStart::GameStart()
{
}

GameStart::GameStart(HINSTANCE g_hInst, HWND hWnd)
	:Layer(hWnd)
{
	gamemap = new gBitmap;

	gamemap->SetBitmap(hWnd, g_hInst, IDB_GAMESTARTMAP);
}

GameStart::~GameStart()
{
	delete gamemap;
	gamemap = NULL;

	printf("GameStart Å¬·¡½º ¼Ò¸ê!\n");
}

void GameStart::DrawBitmap()
{
	gamemap->set_X(0);
	gamemap->set_Y(0);
	this->Draw_BitBlt(gamemap);



	this->Draw();
}
