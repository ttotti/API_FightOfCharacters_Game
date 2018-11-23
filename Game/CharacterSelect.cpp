#include "CharacterSelect.h"

CharacterSelect::CharacterSelect()
{
}

CharacterSelect::CharacterSelect(HINSTANCE g_hInst, HWND hWnd)
	:Layer(hWnd)
{
	BG_bitmap = new gBitmap;
	Home_bitmap = new gBitmap;
	ClickHome_bitmap = new gBitmap;

	chirnoface = new gBitmap;

	BG_bitmap->SetBitmap(hWnd, g_hInst, IDB_SELECT);
	Home_bitmap->SetBitmap(hWnd, g_hInst, IDB_HOME);
	ClickHome_bitmap->SetBitmap(hWnd, g_hInst, IDB_HOMECLICK);

	chirnoface->SetBitmap(hWnd, g_hInst, IDB_CHIRNOFACE);
}

CharacterSelect::~CharacterSelect()
{
	delete BG_bitmap;
	delete Home_bitmap;
	delete ClickHome_bitmap;

	delete chirnoface;

	BG_bitmap = NULL;
	Home_bitmap = NULL;
	ClickHome_bitmap = NULL;

	chirnoface = NULL;
}

void CharacterSelect::init(HINSTANCE g_hInst, HWND hWnd)
{
}

void CharacterSelect::DrawBitmap()
{
	BG_bitmap->set_AllPoint(0, 0, WIN_WIGHT, WIN_HEIGHT);
	this->Draw_StretchBit(BG_bitmap);

	Home_bitmap->set_X(50);
	Home_bitmap->set_Y(666);
	this->Draw_BitBlt(Home_bitmap);

	chirnoface->set_X(100);
	chirnoface->set_Y(100);
	this->Draw_TransparentBlt(chirnoface, 255, 0, 255);

	if (M_x >= 50 && M_x <= Home_bitmap->GetWidth() + 50 && M_y >= 666 && M_y <= Home_bitmap->GetHeight() + 666)
	{
		ClickHome_bitmap->set_X(50);
		ClickHome_bitmap->set_Y(666);
		this->Draw_BitBlt(ClickHome_bitmap);
	}

	this->Draw();
}

void CharacterSelect::MousePoint(int x, int y)
{
	M_x = x;
	M_y = y;
}
