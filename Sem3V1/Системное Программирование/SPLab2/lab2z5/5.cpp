#include <iostream>
#include <windows.h>

using namespace std;

int main() {

	SetConsoleOutputCP(1251);

	int PID;
	cout << "Введите PID процесса:  " << endl;
	cin >> PID;

	HANDLE WalkingDead = OpenProcess(PROCESS_TERMINATE, FALSE, PID);
	if (TerminateProcess(WalkingDead, PID) == TRUE) {
		cout << "Процесс был принудительно завершён" << endl;
	}
	else cout << "Процесс с заданным PID не найден" << endl;

	system("pause");
	return 0;
}