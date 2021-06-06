#include <iostream>
#include <windows.h>

using namespace std;

DWORD WINAPI WorkerThread(LPVOID param) { 
	while (true) {
		cout << *((unsigned*)param) << " ";
	}
}

int main() {

	SetConsoleOutputCP(1251);

	DWORD TID;
	DWORD TID2;

	DWORD NUM = 1;
	DWORD NUM2 = 2;

	if (!CreateThread(NULL, 0, WorkerThread, (void*)&NUM, 0, &TID)|| !CreateThread(NULL, 0, WorkerThread, (void*)&NUM2, 0, &TID2)) {
		cout << "Ошибка создания потока" << GetLastError() << endl;
		system("pause");
		return -1;
	}

	system("pause");
	return 0;
}
