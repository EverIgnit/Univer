#include <windows.h>
#include <stdlib.h>
#include <string>
#include <tchar.h>   
// The main window class name.
static TCHAR szWindowClass[] = _T("win32app");
// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("ChristmasTree");
HINSTANCE hInst;
// Forward declarations of functions included in this code module:
LRESULT CALLBACK  WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS wcl;
	wcl.style = CS_HREDRAW | CS_VREDRAW;
	wcl.lpfnWndProc = WndProc; //указатель на оконную функцию
	wcl.cbClsExtra = 0; // Количество дополнительных данных 
	wcl.cbWndExtra = 0; // Количество дополнительных данных 
	wcl.hInstance = hInstance; //Идентифицирует экземпляр приложения
	wcl.hIcon = LoadIcon(NULL, IDI_WINLOGO); //Дескриптор пиктограммы приложения
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW); //Дескриптор курсора мыши 
	wcl.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); //Дескриптор кисти для заполнения окна
	wcl.lpszMenuName = NULL;
	wcl.lpszClassName = szWindowClass;
	if (!RegisterClass(&wcl))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Win32 Guided Tour"),
			NULL);
		return 1;
	}
	hInst = hInstance;
	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		400, 400,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Win32 Guided Tour"),
			NULL);
		return 1;
	}
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	// Main message loop:
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hDC;
	HPEN hBorders = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	HPEN hGarlandRed = CreatePen(PS_SOLID, 4, RGB(255, 0, 0));
	HPEN hGarlandGreen = CreatePen(PS_SOLID, 4, RGB(0, 255, 0));
	HPEN hGarlandBlue = CreatePen(PS_SOLID, 4, RGB(0, 0, 255));
	HBRUSH hBackground = CreateHatchBrush(HS_FDIAGONAL, RGB(176, 196, 222));
	HBRUSH hFir = CreateSolidBrush(RGB(0, 128, 0));
	HBRUSH hBallDBlue = CreateSolidBrush(RGB(30, 144, 255));
	HBRUSH hMagenta = CreateSolidBrush(RGB(255, 0, 255));
	HBRUSH hYellow = CreateSolidBrush(RGB(255, 255, 0));
	HBRUSH hSilver = CreateSolidBrush(RGB(192, 192, 192));
	HBRUSH hLog = CreateSolidBrush(RGB(139, 69, 19));
	HBRUSH hTop = CreateSolidBrush(RGB(218, 165, 32));
	POINT up[3] = { { 200, 100 },{ 250, 225 },{ 150, 225 } };
	POINT middle[3] = { { 200, 150 },{ 275, 260 },{ 125, 260 } };
	POINT down[3] = { { 200, 190 },{ 285, 300 },{ 115, 300 } };
	POINT top[3] = { { 200, 85 },{ 205, 105 },{ 195, 105 } };
	/*
	HPEN hLapa = CreatePen(PS_SOLID, 5, RGB(127, 0, 0));
	HPEN hShtrixPunctir = CreatePen(PS_DASHDOT, 1, RGB(0, 0, 255));
	HPEN hRot = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	HBRUSH hBody = CreateSolidBrush(RGB(255, 255, 255));
	HBRUSH hEye = CreateSolidBrush(RGB(0, 148, 255));
	HBRUSH hFoot = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH hHat = CreateSolidBrush(RGB(44, 135, 255));
	HBRUSH hNouse = CreateSolidBrush(RGB(255, 105, 0));
	POINT poly[4] = { { 250, 175 },{ 275, 100 },{ 325, 100 },{ 350, 175 } };
	POINT polyN[3] = { { 300, 200 },{ 340, 210 },{ 300, 220 } };
	*/
	switch (message)
	{
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);

		SelectObject(hDC, hBackground); // Фоновые линии
		Rectangle(hDC, 0, 0, 400, 400);

		SelectObject(hDC, hBorders); // Края (обводка)

		SelectObject(hDC, hFir);
		Polygon(hDC, up, 3); // Верхняя часть ёлки
		Polygon(hDC, middle, 3); // Средняя часть ёлки
		Polygon(hDC, down, 3); // Нижняя часть ёлки

		SelectObject(hDC, hLog);
		Rectangle(hDC, 190, 300, 210, 350); // Ствол

		SelectObject(hDC, hTop); // Верхушка
		Polygon(hDC, top, 3);

		SelectObject(hDC, hBallDBlue); // Цвет шара
		Ellipse(hDC, 217, 152, 203, 138); // Декоративный шарик 1
		SelectObject(hDC, hMagenta);
		Ellipse(hDC, 242, 237, 228, 223); // Декоративный шарик 2
		SelectObject(hDC, hYellow);
		Ellipse(hDC, 182, 197, 168, 183); // Декоративный шарик 3
		SelectObject(hDC, hSilver);
		Ellipse(hDC, 157, 282, 143, 268); // Декоративный шарик 4

		SelectObject(hDC, hGarlandBlue); // Цвет гирлянды
		MoveToEx(hDC, 190, 125, NULL); // Нижняя гирлянда
		LineTo(hDC, 215, 135);

		SelectObject(hDC, hGarlandRed); // Цвет гирлянды
		MoveToEx(hDC, 170, 175, NULL); // Средняя гирлянда
		LineTo(hDC, 245, 210);

		SelectObject(hDC, hGarlandGreen); // Цвет гирлянды
		MoveToEx(hDC, 140, 235, NULL); // Верхняя гирлянда
		LineTo(hDC, 275, 275);

		/*
		SelectObject(hDC, hBody); // body 
		Ellipse(hDC, 250, 150, 350, 250);
		Ellipse(hDC, 200, 250, 400, 450);
		Ellipse(hDC, 150, 450, 450, 750);

		SelectObject(hDC, hLapa); //left hand
		MoveToEx(hDC, 200, 350, NULL);
		LineTo(hDC, 150, 300);
		MoveToEx(hDC, 175, 325, NULL);
		LineTo(hDC, 150, 275);
		MoveToEx(hDC, 175, 325, NULL);
		LineTo(hDC, 150, 325);

		SelectObject(hDC, hLapa); //right hand
		MoveToEx(hDC, 400, 350, NULL);
		LineTo(hDC, 450, 300);
		MoveToEx(hDC, 425, 325, NULL);
		LineTo(hDC, 450, 275);
		MoveToEx(hDC, 425, 325, NULL);
		LineTo(hDC, 450, 325);


		SelectObject(hDC, hFoot);
		RoundRect(hDC, 350, 725, 450, 750, 25, 100);  //right
		RoundRect(hDC, 150, 725, 250, 750, 25, 100);  //left

		SelectObject(hDC, hShtrixPunctir);
		MoveToEx(hDC, 300, 300, NULL); // tshirtline
		LineTo(hDC, 300, 400);

		SelectObject(hDC, hTonk);
		SelectObject(hDC, hHat);

		Polygon(hDC, poly, 4); // hat
		SelectObject(hDC, hEye); // eyes
		Ellipse(hDC, 275, 180, 280, 190);
		Ellipse(hDC, 320, 180, 325, 190);

		SelectObject(hDC, hNouse);
		Polygon(hDC, polyN, 3); // nos
		

		SelectObject(hDC, hRot);
		Arc(hDC, 280, 210, 320, 240, 0, 220, 320, 220); //rot
		*/
		TextOut(hDC, 10, 10, L"Christmas Tree by Bialkevich Hleb", 33);

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}