#include "SpellSelectScene.h"

SpellSelectScene::SpellSelectScene()
{
}

SpellSelectScene::SpellSelectScene(HINSTANCE g_hInst, HWND hWnd)
	:Layer(hWnd)
{
	background = new gBitmap;

	background->SetBitmap(hWnd, g_hInst, IDB_SPELLSCENE);

	chirno = new Chirno(g_hInst, hWnd);
}

SpellSelectScene::~SpellSelectScene()
{
	delete background;
	background = NULL;

	printf("SpellSelectScene Å¬·¡½º ¼Ò¸ê!\n");
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

	if (selectCharacter == m_Chirno)
	{
		//chirno->DrawBitmap();
		chirno->ChirnoCard[0]->set_X(100);
		chirno->ChirnoCard[0]->set_AllPoint(300, 300, 100, 100);
		this->Draw_PNGImage(chirno->ChirnoCard[0]);
	}

	this->Draw();
}

void SpellSelectScene::setCharacter(int character_number)
{
	selectCharacter = character_number;
}
