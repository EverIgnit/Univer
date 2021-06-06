// Белькевич Глеб Александрович - 11 группа - Вар 2
#include "Header.h"
#include <windows.h>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <tchar.h>
using namespace std;

static TCHAR szWindowClass[] = _T("win32app");
static TCHAR szTitle[] = _T("Lands");
HINSTANCE hInst;
LRESULT CALLBACK  WndProc(HWND, UINT, WPARAM, LPARAM);

/*
int main(int argc, char* argv[]) {
	//int n;
	ifstream in("vvod.txt");
	if (!in.is_open()) {
		cout << "Ошибка записи в файл " << endl;
		system("pause");
		return 0;
	}
	string st;
	getline(in, st);
	SetOfLands set;
	in >> set;
	in.close(); 
	set.sort();
	system("pause");
	return 0;
}
*/

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
			_T("Lands"),
			NULL);
		return 1;
	}
	hInst = hInstance;
	HWND hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 400, 400, NULL, NULL, hInstance, NULL);
	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Lands"),
			NULL);
		return 1;
	}
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
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
	HBRUSH hBackground = CreateHatchBrush(HS_FDIAGONAL, RGB(176, 196, 222));
	HBRUSH hLand = CreateSolidBrush(RGB(0, 128, 0));

	
	ifstream in("vvod.txt");
	if (!in.is_open()) {
		cout << "Ошибка записи в файл " << endl;
		system("pause");
		return 0;
	}
	string st;
	getline(in, st);
	SetOfLands set;
	in >> set;
	in.close();
	set.sort();
	vector<LAND> lands = set.getvector();
	vector<LAND>::iterator iter;

	switch (message)
	{
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);

		SelectObject(hDC, hBackground); // Фоновые линии
		Rectangle(hDC, 0, 0, 400, 400);

		SelectObject(hDC, hBorders); // Края (обводка)
		
		// Рисуем участки
		for (iter = lands.begin(); iter < lands.begin()+3; iter++) {
			SelectObject(hDC, hLand);
			Rectangle(hDC, (*iter).getx(), (*iter).gety(), (*iter).getx() + (*iter).geta(), (*iter).gety() + (*iter).getb());
		}

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	//system("pause");
	return 0;
}
