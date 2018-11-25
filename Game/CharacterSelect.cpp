#include "CharacterSelect.h"

CharacterSelect::CharacterSelect()
{
}

CharacterSelect::CharacterSelect(HINSTANCE g_hInst, HWND hWnd)
	:Layer(hWnd)
{
	selectCharacter = 0;

	BG_bitmap = new gBitmap;
	Home_bitmap = new gBitmap;
	ClickHome_bitmap = new gBitmap;

	BG_bitmap->SetBitmap(hWnd, g_hInst, IDB_SELECT);
	Home_bitmap->SetBitmap(hWnd, g_hInst, IDB_HOME);
	ClickHome_bitmap->SetBitmap(hWnd, g_hInst, IDB_HOMECLICK);


	chirnoface = new gBitmap;
	hong_meiling = new gBitmap;

	chirnoface->SetBitmap(hWnd, g_hInst, IDB_CHIRNOFACE);
	hong_meiling->SetBitmap(hWnd, g_hInst, IDB_HONG);
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

	chirnoface->set_X(WIN_WIGHT/2-300);
	chirnoface->set_Y(WIN_HEIGHT/2-100);
	this->Draw_TransparentBlt(chirnoface, 255, 0, 255);

	hong_meiling->set_X(chirnoface->get_X()+chirnoface->GetWidth());
	hong_meiling->set_Y(WIN_HEIGHT / 2 - 100);
	this->Draw_TransparentBlt(hong_meiling, 255, 0, 255);
	
	if (GameLoop::M_x >= 50 && GameLoop::M_x <= Home_bitmap->GetWidth() + 50 && GameLoop::M_y >= 666 && GameLoop::M_y <= Home_bitmap->GetHeight() + 666)
	{
		ClickHome_bitmap->set_X(50);
		ClickHome_bitmap->set_Y(666);
		this->Draw_BitBlt(ClickHome_bitmap);
	}

	this->Draw();
}

bool CharacterSelect::ClickCharacter()
{
	printf("chirnoface->get_X() = %f\n", chirnoface->get_X());
	printf("chirnoface->GetWidth() = %d\n", chirnoface->GetWidth());
	printf("chirnoface->get_Y() = %f\n", chirnoface->get_Y());
	printf("chirnoface->GetHeight() = %d\n", chirnoface->GetHeight());

	printf("GameLoop::C_x = %d\n", GameLoop::C_x);
	printf("GameLoop::C_y = %d\n\n", GameLoop::C_y);


	if (GameLoop::C_x >= chirnoface->get_X() && GameLoop::C_x <= chirnoface->get_X()+chirnoface->GetWidth() && GameLoop::C_y >= chirnoface->get_Y() && GameLoop::C_y <= chirnoface->get_Y()+chirnoface->GetHeight())
	{
		selectCharacter = Chirno;

		printf("치르노 클릭!\n");

		return true;
	}

	return false;
}
