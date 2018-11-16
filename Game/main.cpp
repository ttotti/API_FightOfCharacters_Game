#include <Windows.h> // �������

#include "GameLoop.h"

#pragma comment(linker,"/entry:WinMainCRTStartup /subsystem:console")

//#ifdef UNICODE
//#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
//#else
//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
//#endif

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst; // ���� API�Լ����� �ν��Ͻ� ���� �䱸�ϴµ� hInstance �μ��� ���������̱� ������ WinMain �ۿ��� �������� �׷��� �������� g_hinst�� �����صд�
LPCTSTR lpszClass = TEXT("Class");

// ������
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0; // ������ ���࿵�� ������� ���������� ����ϸ� ���� Ư���� ������ ���Ǵ� ������ �����̴�
	WndClass.cbWndExtra = 0; // ���࿵���� ������� ���� ��� 0���� �����Ѵ�
	WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // �� ������ ����ڰ� �����ǿ��� ������ �������� �����̸� �ý��� �����̶�� �Ѵ�(�ý��� ������ ���� �ٲ���ִ�(���뼺))
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW); // �����찡 ����� ���콺 Ŀ���� �������� �����Ѵ�
	WndClass.hIcon = LoadIcon(NULL, IDI_ERROR);
	WndClass.hInstance = hInstance; // ������ Ŭ������ ����ϴ� ���α׷��� ��ȣ�̸� WinMain�� �μ��� ���޵� hinstance���� �״�� �����ϸ� �ȴ�
	WndClass.lpfnWndProc = WndProc; // �������� �޽��� ó�� �Լ��� �����Ѵ�
	WndClass.lpszClassName = lpszClass; // ������ Ŭ������ �̸��� ���ڿ��� �����Ѵ�
	WndClass.lpszMenuName = NULL; // �� ���α׷��� ����� �޴��� �����Ѵ� // ���ҽ� �����Ϳ� ���� ������ ������� ��ũ�ÿ� ���� ��������
	WndClass.style = CS_HREDRAW | CS_VREDRAW; // �����찡 � ���¸� ���� ���ΰ��� �����ϴ� ���
	RegisterClass(&WndClass); // WNDCLASS ����ü�� ������ �����Ѵ� // �̷� Ư���� ���� �����츦 ������ ����ϰڴٴ� ��� �����̴�

							  // ������ ����
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, WIN_WIGHT, WIN_HEIGHT, NULL, (HMENU)NULL, hInstance, NULL);
	// �޸𸮿� ������� �����츦 ȭ�鿡 ���̰� �ϴ� �Լ�
	ShowWindow(hWnd, nCmdShow);

	// �޽��� ����
	while (GetMessage(&Message, NULL, 0, 0)) // LPMSG IpMsg ù��° �μ� // �޽��� ť���� �޽����� �о��� WN_QUIT �ϰ�� FALSE�� �����ϸ� �������� TRUE�� �����Ѵ� // �������μ��� �� �Ⱦ���
	{
		TranslateMessage(&Message); // Ű���� �Է� �޽����� �����Ͽ� ���α׷����� ���� �� �� �ֵ��� �Ѵ�
		DispatchMessage(&Message); // �޽��� ť���� ���� �޽����� �������� �޽��� ó�� �Լ�(WndProc)�� �����Ѵ�
	}

	return (int)Message.wParam;
}

void MyText(HDC hdc, int x, int y, LPCTSTR Text)
{
	TextOut(hdc, x, y, Text, lstrlen(Text));
}

GameLoop gameloop;

// ����ڿ� �ý����� �������� �޽����� ó���ϴ� ���� �߿��� ���� �Ѵ�
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	HWND hWndMain;

	int x, y;
	 
	switch (iMessage)
	{
	case WM_CREATE:
		hWndMain = hWnd;

		gameloop.init(g_hInst, hWnd);

		SetTimer(hWnd, 1, 100, NULL);

		return 0;

	case WM_TIMER:
		gameloop.updata();
		gameloop.Loop(g_hInst, hWnd);

		//InvalidateRect(hWnd, NULL, FALSE);
		return 0;

	//case WM_PAINT:
	//	hdc = BeginPaint(hWnd, &ps);

	//	gameloop.DrawBitmap(hdc);

	//	printf("C_x = %d, C_y = %d\n", gameloop.C_x, gameloop.C_y);

	//	//printf("WM_PAINT ȣ��!\n");

	//	EndPaint(hWnd, &ps);
	//	return 0;

	case WM_MOUSEMOVE:
		gameloop.M_x = LOWORD(lParam);
		gameloop.M_y = HIWORD(lParam);

		//switch (gameloop.selectMenu)
		//{
		//case MAINSCENE:
		//{
		//	if (LOWORD(lParam) >= 485 && LOWORD(lParam) <= 752 && HIWORD(lParam) >= 496 && HIWORD(lParam) <= 629)
		//	{
		//		gameloop.mousePoint = true;
		//		printf("true\n");
		//	}
		//	else
		//	{
		//		gameloop.mousePoint = false;
		//		printf("false\n");
		//	}
		//	
		//	gameloop.x = LOWORD(lParam);
		//	gameloop.y = HIWORD(lParam);

		//	return 0;
		//}
		//default:
		//	break;
		//}
		printf("x = %d  y = %d\n", LOWORD(lParam), HIWORD(lParam));
		return 0;

	case WM_LBUTTONDOWN:
		gameloop.C_x = LOWORD(lParam);
		gameloop.C_y = HIWORD(lParam);

		return 0;

	case WM_LBUTTONUP:
		gameloop.C_x = 0;
		gameloop.C_y = 0;

		return 0;

	case WM_DESTROY:
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

/*
	2018/11/04
	��� ��� (�Ϸ�)

	2018/11/05
	��Ʈ���� ����ϴ� Ŭ���� �����(�Ϸ�)
	- ���� -
	Bitmap Ŭ������ WndProc �ȿ� �����ϰ� WM_CREATE ���� SetBitmap() �Լ��� ����Ͽ� ��Ʈ���� �����ߴµ�
	�޽����� ȣ��ǰ� ���� �� Ŭ������ �Ҹ�ȴ�
	�׷��� ��Ʈ���� �������� �ʰ� NULL������ ����Ͽ� �׳� ��ȭ�鸸 ���δ�
	- �ذ� -
	Bitmap Ŭ������ WndProc ������ �� ���������� �����Ͽ���

	2018/11/07
	Ÿ�� ��ǥ Ŭ���� �����(���� ��)

	2018/11/08
	Ÿ�� ��ǥ Ŭ���� �����(�Ϸ�)
	���� ���� Ŭ���� �����(���� ��)
	���� ���� ȭ�� ��ư�̹��� Ȱ��ȭ �� ��Ȱ��ȭ ��� (�Ϸ�)

	2018/11/09
	GameLoop Ŭ���� �Լ��̸� ���� DrawBitmap() -> Loop()
	���� ȭ���� ��Ÿ���� mainScene Ŭ���� �����(�Ϸ�)
	ĳ���� ���� ȭ���� ��Ÿ���� CharacterSelect Ŭ���� �����(�Ϸ�)

	2018/11/11
	������۸� �����ϱ�(���� ��)
	���� ���� Ŭ���� �����(���� ��)
	InvalidateRect() �� ��° �μ� ���� TRUE -> FALSE

	2018/11/13
	������۸� �����ϱ�(���� ��)
	���� ���� Ŭ���� �����(���� ��)
	(����) gameLoop.init() ���� �� Ŭ������ ��Ʈ�� �ʱ�ȭ -> (����) �� Ŭ���� ���� init() �Լ��� ����� ��Ʈ�� �ʱ�ȭ
	WM_MOUSEMOVE ���� ���콺�� ��ǥ�� ������ ����
	point Ŭ���� �̸� ���� Point -> Rect_Point

	2018/11/14

*/