#include <windows.h> 
#include <iostream> 


using namespace std;

DWORD WINAPI WorkerThread(LPVOID param) {
	while (true) {
		short Melody[] = { 520, 880, 880, 780, 880, 700, 520, 520 };
		for (int i = 0; i < sizeof(Melody) / sizeof(short); i++)
		{
			Beep(Melody[i], 400);
		}
	}
}

int main() {

	SetConsoleOutputCP(1251);

	HANDLE Thread;
	DWORD TID;
	DWORD Num = 2;
	int k;

	Thread = CreateThread(NULL, 0, WorkerThread, (void*)&Num, CREATE_SUSPENDED, &TID);
	if (Thread == NULL) {
		cout << "Ошибка" << GetLastError() << endl;  //код ошибки
		system("pause");
		return -1;
	}
	bool a = true;
	while (a) {
		cout << "Выберете действие: \n 1) Приостановить \n 2) Возобновить\n 3) Завершить\n";
		cin >> k;
		switch (k) {
		case 1:
			SuspendThread(Thread);
			break;
		case 2:
			ResumeThread(Thread);
			break;
		case 3:
			TerminateThread(Thread, -1);
			a = false;
			break;
		default:
			cout << "Введите верное значение (1/2/3)!" << endl;
			break;

		}
	}
	system("pause");
	return 0;
}
