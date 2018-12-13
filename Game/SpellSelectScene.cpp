#include "SpellSelectScene.h"

SpellSelectScene::SpellSelectScene()
{
}

SpellSelectScene::SpellSelectScene(HINSTANCE g_hInst, HWND hWnd)
	:Layer(g_hInst, hWnd)
{
	Home_bitmap = new gBitmap;
	Home_bitmap->SetBitmap(hWnd, g_hInst, IDB_HOME);

	background = new PNG_Image;

	background->LoadPNG(g_hInst, IDB_Cardmap);

	MovingUp = new PNG_Image;
	MovingDown = new PNG_Image;
	MovingLeft = new PNG_Image;
	MovingRight = new PNG_Image;

	MovingUp->LoadPNG(g_hInst, IDB_pUp);
	MovingDown->LoadPNG(g_hInst, IDB_pDown);
	MovingLeft->LoadPNG(g_hInst, IDB_pLeft);
	MovingRight->LoadPNG(g_hInst, IDB_pRight);

	LifeBar = new PNG_Image;
	HPLife = new PNG_Image;
	MPLife = new PNG_Image;

	LifeBar->LoadPNG(g_hInst, IDB_pLifebar);
	HPLife->LoadPNG(g_hInst, IDB_pHPLife);
	MPLife->LoadPNG(g_hInst, IDB_pMPLife);

	chirno = NULL;
}

SpellSelectScene::~SpellSelectScene()
{
	delete Home_bitmap;
	Home_bitmap = NULL;

	delete background;
	background = NULL;

	delete MovingUp;
	MovingUp = NULL;

	delete MovingDown;
	MovingUp = NULL;

	delete MovingLeft;
	MovingUp = NULL;

	delete MovingRight;
	MovingUp = NULL;

	delete LifeBar;
	LifeBar = NULL;

	delete HPLife;
	HPLife = NULL;

	delete MPLife;
	MPLife = NULL;

	delete chirno;
	chirno = NULL;

	printf("SpellSelectScene Å¬·¡½º ¼Ò¸ê!\n");
}

void SpellSelectScene::DrawBitmap()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			background->set_X(i*background->GetWidth());
			background->set_Y(j*background->GetHeight());
			this->Draw_PNGImage(background);
		}
	}

	Home_bitmap->set_X(50);
	Home_bitmap->set_Y(666);
	this->Draw_BitBlt(Home_bitmap);

	LifeBar->set_AllPoint(170, 0, LifeBar->GetWidth() + 100, 40);
	this->Draw_PNGImage(LifeBar);

	MovingUp->set_AllPoint((WIN_WIGHT / 2) / 2, (WIN_HEIGHT / 2) / 2, MovingUp->GetWidth() * 2, MovingUp->GetHeight() * 2);
	MovingDown->set_AllPoint((WIN_WIGHT / 2) / 2 + 100, (WIN_HEIGHT / 2) / 2, MovingDown->GetWidth() * 2, MovingDown->GetHeight() * 2);
	MovingLeft->set_AllPoint((WIN_WIGHT / 2) / 2 + 200, (WIN_HEIGHT / 2) / 2, MovingLeft->GetWidth() * 2, MovingLeft->GetHeight() * 2);
	MovingRight->set_AllPoint((WIN_WIGHT / 2) / 2 + 300, (WIN_HEIGHT / 2) / 2, MovingRight->GetWidth() * 2, MovingRight->GetHeight() * 2);

	this->Draw_PNGImage(MovingUp);
	this->Draw_PNGImage(MovingDown);
	this->Draw_PNGImage(MovingLeft);
	this->Draw_PNGImage(MovingRight);

	if (selectCharacter == m_Chirno)
	{
		if (chirno == NULL)
		{
			chirno = new Chirno(this->Get_g_hInst(), this->Get_hWnd());
		}

		chirno->Chirnoface->set_AllPoint(0, 0, chirno->Chirnoface->GetWidth()+50, chirno->Chirnoface->GetHeight()+30);
		this->Draw_PNGImage(chirno->Chirnoface);

		int x = 0;

		for (int i = 0; i < MAX_Card; i++)
		{
			chirno->ChirnoCard[i]->set_AllPoint((WIN_WIGHT / 2) / 2 + x, (WIN_HEIGHT / 2) / 2+140, chirno->ChirnoCard[i]->GetWidth() * 2, chirno->ChirnoCard[i]->GetHeight() * 2);
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
