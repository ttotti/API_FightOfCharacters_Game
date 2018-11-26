#include "SpellSelectScene.h"

SpellSelectScene::SpellSelectScene()
{
}

SpellSelectScene::SpellSelectScene(HINSTANCE g_hInst, HWND hWnd)
	:Layer(hWnd)
{
	background = new gBitmap;

	background->SetBitmap(hWnd, g_hInst, IDB_SPELLSCENE);
}

SpellSelectScene::~SpellSelectScene()
{
	delete background;

	background = NULL;
}

void SpellSelectScene::DrawBitmap()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			background->set_X(i*background->GetWidth());
			background->set_Y(j*background->GetHeight());
			this->Draw_BitBlt(background);
		}
	}

	this->Draw();
}
