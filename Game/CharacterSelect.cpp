#include "CharacterSelect.h"

CharacterSelect::CharacterSelect()
{
}

CharacterSelect::~CharacterSelect()
{
}

void CharacterSelect::init(HINSTANCE g_hInst)
{
	BG_bitmap.SetBitmap(g_hInst, IDB_SELECT);
}
