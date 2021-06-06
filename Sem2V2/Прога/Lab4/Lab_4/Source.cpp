#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>  
#include "func.h"  

// Global variables
#define idEdit1 101
#define idEdit2 102
#define idButton 201

// The main window class name.
static TCHAR szWindowClass[] = _T("win32app");
// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Деление чисел");

// Forward declarations of functions included in this code module:
LRESULT CALLBACK  WndProc(HWND, UINT, WPARAM, LPARAM);

void ButtonClick(HWND hWnd);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS wcl;
	wcl.hInstance = hInstance; /* Идентифицирует экземпляр приложения */
	wcl.lpszClassName = L"MyWindowClass"; /* Уникальное имя класса окна */
	wcl.lpfnWndProc = WndProc; /* Указатель на оконную функцию */
	wcl.style = CS_HREDRAW | CS_VREDRAW; /* Стиль класса окна */
	wcl.lpszMenuName = NULL; /* Имя ресурса меню по умолчанию */
	wcl.hIcon = LoadIcon(NULL, IDI_WINLOGO); /* Дескриптор пиктограммы приложения */
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW); /* Дескриптор курсора мыши */
	wcl.hbrBackground = (HBRUSH)COLOR_WINDOW; /* Дескриптор кисти для заполнения окна */
	wcl.cbClsExtra = 0; /* Количество дополнительных данных */
	wcl.cbWndExtra = 0; /* Количество дополнительных данных */


	if (!RegisterClass(&wcl)) {
		MessageBox(NULL,
			_T("Call to RegisterClass failed!"),
			_T("Win32 Guided Tour"),
			NULL);
		return 1;
	}

	HWND hWnd;
	hWnd = CreateWindow(
		L"MyWindowClass", // Имя класса окна
		L"Devide", // Заголовок окна
		WS_OVERLAPPEDWINDOW, // Стиль окна
		670, 300, // Координаты левого верхнего угла
		250, 250, // Размеры окна
		HWND_DESKTOP, // Дескриптор родительского окна
		NULL, // Дескриптор главного меню
		hInstance, // Дескриптор приложения-создателя
		NULL // Указатель на массив дополнительных данных окна

	);
	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	/* Отображение окна */
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	CreateWindow(
		L"STATIC", // класс окна
		L"Введите первое значение", // текст надписи
		WS_CHILD | WS_VISIBLE, // стиль окна
		10, 10, // координаты
		200, 20, // размер
		hWnd, // родительское окно
		(HMENU)1, // идентификатор элемента
		hInstance, // дескриптор приложения
		NULL
	);
	CreateWindow(L"EDIT", L"",
		WS_CHILD | WS_VISIBLE | WS_BORDER, 10, 25, 175, 25,
		hWnd, (HMENU)idEdit1, hInstance, NULL);

	CreateWindow(
		L"STATIC",
		L"Введите второе значение",
		WS_CHILD | WS_VISIBLE,
		10, 50,
		200, 20,
		hWnd,
		(HMENU)2,
		hInstance,
		NULL
	);

	CreateWindow(L"EDIT", L"",
		WS_CHILD | WS_VISIBLE | WS_BORDER, 10, 65, 175, 25,
		hWnd, (HMENU)idEdit2, hInstance, NULL);
	CreateWindow(L"BUTTON", L"Разделить", WS_CHILD | WS_VISIBLE,
		10, 135, 175, 25, hWnd, (HMENU)idButton, hInstance, NULL);

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
	switch (message)
	{
	case WM_COMMAND:
		if (HIWORD(wParam) == BN_CLICKED)
			switch (LOWORD(wParam)) {
			case idButton:
				ButtonClick(hWnd);
				break;
			}
		break;
	case WM_DESTROY: // сообщение "окно разрушено"
		PostQuitMessage(0); // послать сообщение "выход из программы" 
		break;
	default: // все остальные сообщения обрабатываются функцией по умолчанию 
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}

void ButtonClick(HWND hWnd) {
	// определение дескриптора окна редактирования
	HWND hEdit1 = GetDlgItem(hWnd, idEdit1);
	HWND hEdit2 = GetDlgItem(hWnd, idEdit2);
	// Считывание данных
	TCHAR str[100];
	GetWindowText(hEdit1, str, 100);
	int x = _tstoi(str);
	GetWindowText(hEdit2, str, 100);
	int y = _tstoi(str);
	// Решение
	Num A(x, y);
	// формирование ответа и вывод на экран
	A.func(str);
	MessageBox(hWnd, str, L"Ответ",
		MB_OK | MB_ICONINFORMATION);

}