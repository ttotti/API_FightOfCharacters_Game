#include <Windows.h> // 헤더파일

#include "GameLoop.h"

#pragma comment(linker,"/entry:WinMainCRTStartup /subsystem:console")

//#ifdef UNICODE
//#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
//#else
//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
//#endif

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst; // 많은 API함수들이 인스턴스 값을 요구하는데 hInstance 인수는 지역변수이기 때문에 WinMain 밖에서 쓸수없다 그래서 전역변수 g_hinst에 대입해둔다
LPCTSTR lpszClass = TEXT("Class");

// 시작점
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0; // 일종의 예약영역 윈도우즈가 내부적으로 사용하며 아주 특수한 목적에 사용되는 여분의 공간이다
	WndClass.cbWndExtra = 0; // 예약영역을 사용하지 않을 경우 0으로 지정한다
	WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // 이 색상은 사용자가 제어판에서 선택한 윈도우의 배경색이며 시스템 색상이라고 한다(시스템 설정에 따라 바뀔수있다(범용성))
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW); // 윈도우가 사용할 마우스 커서와 아이콘을 지정한다
	WndClass.hIcon = LoadIcon(NULL, IDI_ERROR);
	WndClass.hInstance = hInstance; // 윈도우 클래스를 등록하는 프로그램의 번호이며 WinMain의 인수로 전달된 hinstance값을 그대로 대입하면 된다
	WndClass.lpfnWndProc = WndProc; // 윈도우의 메시지 처리 함수를 지정한다
	WndClass.lpszClassName = lpszClass; // 윈도우 클래스의 이름을 문자열로 정의한다
	WndClass.lpszMenuName = NULL; // 이 프로그램이 사용할 메뉴를 지정한다 // 리소스 에디터에 의해 별도로 만들어져 링크시에 같이 합쳐진다
	WndClass.style = CS_HREDRAW | CS_VREDRAW; // 윈도우가 어떤 형태를 가질 것인가를 지정하는 멤버
	RegisterClass(&WndClass); // WNDCLASS 구조체의 번지를 전달한다 // 이런 특성을 가진 윈도우를 앞으로 사용하겠다는 등록 과정이다

							  // 윈도우 생성
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, WIN_WIGHT, WIN_HEIGHT, NULL, (HMENU)NULL, hInstance, NULL);
	// 메모리에 만들어진 윈도우를 화면에 보이게 하는 함수
	ShowWindow(hWnd, nCmdShow);

	// 메시지 루프
	while (GetMessage(&Message, NULL, 0, 0)) // LPMSG IpMsg 첫번째 인수 // 메시지 큐에서 메시지를 읽어드려 WN_QUIT 일경우 FALSE를 리턴하며 나머지는 TRUE를 리턴한다 // 나머지인수는 잘 안쓴다
	{
		TranslateMessage(&Message); // 키보드 입력 메시지를 가공하여 프로그램에서 쉽게 쓸 수 있도록 한다
		DispatchMessage(&Message); // 메시지 큐에서 꺼낸 메시지를 윈도우의 메시지 처리 함수(WndProc)로 전달한다
	}

	return (int)Message.wParam;
}

void MyText(HDC hdc, int x, int y, LPCTSTR Text)
{
	TextOut(hdc, x, y, Text, lstrlen(Text));
}

GameLoop gameloop;

// 사용자와 시스템이 보내오는 메시지를 처리하는 아주 중요한 일을 한다
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

	//	//printf("WM_PAINT 호출!\n");

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
	배경 출력 (완료)

	2018/11/05
	비트맵을 출력하는 클래스 만들기(완료)
	- 오류 -
	Bitmap 클래스를 WndProc 안에 선언하고 WM_CREATE 에서 SetBitmap() 함수를 사용하여 비트맵을 생성했는데
	메시지가 호출되고 끝날 때 클래스가 소멸된다
	그래서 비트맵은 생성되지 않고 NULL값으로 출력하여 그냥 빈화면만 보인다
	- 해결 -
	Bitmap 클래스를 WndProc 밖으로 즉 전역변수로 선언하였다

	2018/11/07
	타일 좌표 클래스 만들기(진행 중)

	2018/11/08
	타일 좌표 클래스 만들기(완료)
	게임 루프 클래스 만들기(진행 중)
	게임 시작 화면 버튼이미지 활성화 및 비활성화 출력 (완료)

	2018/11/09
	GameLoop 클래스 함수이름 변경 DrawBitmap() -> Loop()
	시작 화면을 나타내는 mainScene 클래스 만들기(완료)
	캐릭터 선택 화면을 나타내는 CharacterSelect 클래스 만들기(완료)

	2018/11/11
	더블버퍼링 구현하기(진행 중)
	게임 루프 클래스 만들기(진행 중)
	InvalidateRect() 세 번째 인수 변경 TRUE -> FALSE

	2018/11/13
	더블버퍼링 구현하기(진행 중)
	게임 루프 클래스 만들기(진행 중)
	(기존) gameLoop.init() 에서 각 클래스의 비트맵 초기화 -> (변경) 각 클래스 별로 init() 함수를 만들어 비트맵 초기화
	WM_MOUSEMOVE 에서 마우스의 좌표만 얻어오게 변경
	point 클래스 이름 변경 Point -> Rect_Point

	2018/11/14

*/