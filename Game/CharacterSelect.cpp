#include "CharacterSelect.h"

CharacterSelect::CharacterSelect()
{
}

CharacterSelect::CharacterSelect(HINSTANCE g_hInst, HWND hWnd)
{
	BG_bitmap.SetBitmap(hWnd, g_hInst, IDB_SELECT);
	Home_bitmap.SetBitmap(hWnd, g_hInst, IDB_HOME);
	ClickHome_bitmap.SetBitmap(hWnd, g_hInst, IDB_HOMECLICK);

	chirnoface.setImage(hWnd, L"Chirnoface.png");
}

CharacterSelect::~CharacterSelect()
{
}

void CharacterSelect::init(HINSTANCE g_hInst, HWND hWnd)
{
	BG_bitmap.SetBitmap(hWnd, g_hInst, IDB_SELECT);
}

void CharacterSelect::DrawBitmap()
{
	BG_bitmap.DramBitmap(0, 0, WIN_WIGHT, WIN_HEIGHT);

	Home_bitmap.DramBitmap(50, 666);

	chirnoface.DrawImage(100, 200);

	if (M_x >= 50 && M_x <= Home_bitmap.GetWight() + 50 && M_y >= 666 && M_y <= Home_bitmap.GetHeight() + 666)
	{
		ClickHome_bitmap.DramBitmap(50, 666);
	}
}

void CharacterSelect::MousePoint(int x, int y)
{
	M_x = x;
	M_y = y;
}
