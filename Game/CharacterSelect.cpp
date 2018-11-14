#include "CharacterSelect.h"

CharacterSelect::CharacterSelect()
{
}

CharacterSelect::~CharacterSelect()
{
}

void CharacterSelect::init(HINSTANCE g_hInst, HWND hWnd)
{
	this->hWnd = hWnd;

	BG_bitmap.SetBitmap(hWnd, g_hInst, IDB_SELECT);
}

void CharacterSelect::DrawBitmap()
{
	BG_bitmap.DramBitmap(0, 0, WIN_WIGHT, WIN_HEIGHT);
}

void CharacterSelect::MousePoint(int x, int y)
{
	M_x = x;
	M_y = y;
}
