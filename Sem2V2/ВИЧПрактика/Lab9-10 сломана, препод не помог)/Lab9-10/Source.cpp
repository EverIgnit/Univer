// ��������� ���� ��� 9, 10
#include "Header.h"
#include <windows.h>
#include <iostream>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ������������� � ����
	PlayList FromMP3;
	// ����� ���� � ���������� ����������
	FromMP3.ConsoleMenu();

	system("pause");
	return 0;
}