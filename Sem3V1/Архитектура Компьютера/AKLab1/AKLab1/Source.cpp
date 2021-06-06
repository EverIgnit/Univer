#include "Header.h"
#include <iostream>
#include <windows.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");

	Bot Arnold;
	Data data;
	Logic logic;
	InpOutp inout;
	do {
		inout.ShowInfo(Arnold, data);
	} while (inout.InP(logic, Arnold, data));

	system("pause");
	return 0;
}