#include <iostream>
#include <windows.h>

using namespace std;

int main() {

	SetConsoleOutputCP(1251);

	int PID;
	cout << "������� PID ��������:  " << endl;
	cin >> PID;

	HANDLE WalkingDead = OpenProcess(PROCESS_TERMINATE, FALSE, PID);
	if (TerminateProcess(WalkingDead, PID) == TRUE) {
		cout << "������� ��� ������������� ��������" << endl;
	}
	else cout << "������� � �������� PID �� ������" << endl;

	system("pause");
	return 0;
}