// Белькевич Глеб Лаб 9, 10
#include "Header.h"
#include <windows.h>
#include <iostream>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Инициализация и ввод
	PlayList FromMP3;
	// Вывод меню и дальнейшие вычисление
	FromMP3.ConsoleMenu();

	system("pause");
	return 0;
}