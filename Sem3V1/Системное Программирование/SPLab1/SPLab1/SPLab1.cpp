#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include "TCHAR.H"
// ��� ������� 4
#ifdef _UNIC00E
#define _tcslen wcslen
#else
#define _tcscout wcout
#endif

using namespace std;

int main() {

	setlocale(LC_ALL, "RUS");
	// ������� 1-3
	/*
	TCHAR str1[28] = TEXT("��������� ����������������");
	_tcscout << str1 << endl;
	int a = _tcslen(str1);
	char* str2 = new char[a];
	WideCharToMultiByte(CP_UTF8, NULL, str1, -1, str2, a + 1, NULL, NULL);
	cout << str2 << endl;
	delete[]str2;
	*/
	// ������� 4
	TCHAR str[10] = TEXT("2342354");
	_tcscout << str << endl;
	system("pause");
	return 0;
}