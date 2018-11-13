#include "mainScene.h"

mainScene::mainScene()
{
}

mainScene::~mainScene()
{
}

void mainScene::init(HINSTANCE g_hInst)
{
	mainbitmap.SetBitmap(g_hInst, IDB_MAINSCENE);
	startbitmap.SetBitmap(g_hInst, IDB_GAMESTART);
	startbitmap2.SetBitmap(g_hInst, IDB_GAMESTART2);
}