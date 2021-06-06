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
static TCHAR szTitle[] = _T("������� �����");

// Forward declarations of functions included in this code module:
LRESULT CALLBACK  WndProc(HWND, UINT, WPARAM, LPARAM);

void ButtonClick(HWND hWnd);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS wcl;
	wcl.hInstance = hInstance; /* �������������� ��������� ���������� */
	wcl.lpszClassName = L"MyWindowClass"; /* ���������� ��� ������ ���� */
	wcl.lpfnWndProc = WndProc; /* ��������� �� ������� ������� */
	wcl.style = CS_HREDRAW | CS_VREDRAW; /* ����� ������ ���� */
	wcl.lpszMenuName = NULL; /* ��� ������� ���� �� ��������� */
	wcl.hIcon = LoadIcon(NULL, IDI_WINLOGO); /* ���������� ����������� ���������� */
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW); /* ���������� ������� ���� */
	wcl.hbrBackground = (HBRUSH)COLOR_WINDOW; /* ���������� ����� ��� ���������� ���� */
	wcl.cbClsExtra = 0; /* ���������� �������������� ������ */
	wcl.cbWndExtra = 0; /* ���������� �������������� ������ */


	if (!RegisterClass(&wcl)) {
		MessageBox(NULL,
			_T("Call to RegisterClass failed!"),
			_T("Win32 Guided Tour"),
			NULL);
		return 1;
	}

	HWND hWnd;
	hWnd = CreateWindow(
		L"MyWindowClass", // ��� ������ ����
		L"Devide", // ��������� ����
		WS_OVERLAPPEDWINDOW, // ����� ����
		670, 300, // ���������� ������ �������� ����
		250, 250, // ������� ����
		HWND_DESKTOP, // ���������� ������������� ����
		NULL, // ���������� �������� ����
		hInstance, // ���������� ����������-���������
		NULL // ��������� �� ������ �������������� ������ ����

	);
	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	/* ����������� ���� */
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	CreateWindow(
		L"STATIC", // ����� ����
		L"������� ������ ��������", // ����� �������
		WS_CHILD | WS_VISIBLE, // ����� ����
		10, 10, // ����������
		200, 20, // ������
		hWnd, // ������������ ����
		(HMENU)1, // ������������� ��������
		hInstance, // ���������� ����������
		NULL
	);
	CreateWindow(L"EDIT", L"",
		WS_CHILD | WS_VISIBLE | WS_BORDER, 10, 25, 175, 25,
		hWnd, (HMENU)idEdit1, hInstance, NULL);

	CreateWindow(
		L"STATIC",
		L"������� ������ ��������",
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
	CreateWindow(L"BUTTON", L"���������", WS_CHILD | WS_VISIBLE,
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
	case WM_DESTROY: // ��������� "���� ���������"
		PostQuitMessage(0); // ������� ��������� "����� �� ���������" 
		break;
	default: // ��� ��������� ��������� �������������� �������� �� ��������� 
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}

void ButtonClick(HWND hWnd) {
	// ����������� ����������� ���� ��������������
	HWND hEdit1 = GetDlgItem(hWnd, idEdit1);
	HWND hEdit2 = GetDlgItem(hWnd, idEdit2);
	// ���������� ������
	TCHAR str[100];
	GetWindowText(hEdit1, str, 100);
	int x = _tstoi(str);
	GetWindowText(hEdit2, str, 100);
	int y = _tstoi(str);
	// �������
	Num A(x, y);
	// ������������ ������ � ����� �� �����
	A.func(str);
	MessageBox(hWnd, str, L"�����",
		MB_OK | MB_ICONINFORMATION);

}