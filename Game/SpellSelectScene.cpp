#include "SpellSelectScene.h"

SpellSelectScene::SpellSelectScene()
{
}

SpellSelectScene::SpellSelectScene(HINSTANCE g_hInst, HWND hWnd)
	:Layer(g_hInst, hWnd)
{
	background = new gBitmap;

	background->SetBitmap(hWnd, g_hInst, IDB_SPELLSCENE);

	chirno = NULL;
}

SpellSelectScene::~SpellSelectScene()
{
	delete background;
	background = NULL;

	delete chirno;
	chirno = NULL;

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
		if (chirno == NULL)
		{
			chirno = new Chirno(this->Get_g_hInst(), this->Get_hWnd());
		}

		int x = 0;

		for (int i = 0; i < MAX_Card; i++)
		{
			chirno->ChirnoCard[i]->set_AllPoint((WIN_WIGHT / 2) / 2+x, (WIN_HEIGHT / 2) / 2, chirno->ChirnoCard[i]->GetWidth() * 2, chirno->ChirnoCard[i]->GetHeight() * 2);
			this->Draw_PNGImage(chirno->ChirnoCard[i]);
			x += 100;
		}
	}

	this->Draw();
}

void SpellSelectScene::setCharacter(int character_number)
{
	selectCharacter = character_number;
}
