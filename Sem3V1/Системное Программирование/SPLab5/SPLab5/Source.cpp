#include <iostream>
#include "windows.h"

using namespace std;

int main() {
	setlocale(0, "");

	int temp = GetCurrentDirectory(0, NULL);
	LPSTR str = new TCHAR[temp];
	if (!GetCurrentDirectory(temp  //buffer size
		,str //the pointer to the buffer
	))
		cout << "������" << endl;
	else
		wcout << str << endl;

	if (!SetCurrentDirectory("C:\\Windows\\Temp")) //new value of the current directory
		cout << "������ ������� �� ����������." << endl;
	else {
		temp = GetCurrentDirectory(0, NULL);
		if (!GetCurrentDirectory(temp, str))
			cout << "������" << endl;
		else
			wcout << str << endl;
	}

	system("pause");
	return 0;
}