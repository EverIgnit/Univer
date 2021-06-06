#include <iostream>
#include <windows.h>

using namespace std;

DWORD WINAPI WorkerThread(LPVOID param) {
	short n = 1;
	while (n <= 30)
	{
		cout << n << " ";
		n++;
	}
	return 1;
}
int main() {

	SetConsoleOutputCP(1251);

	HANDLE Tread;
	DWORD TID;
	DWORD TID2;
	DWORD NUM = 1;
	DWORD NUM2 = 2;

	if (!CreateThread(NULL, 0, WorkerThread, (void*)&NUM, 0, &TID) || !CreateThread(NULL, 0, WorkerThread, (void*)&NUM2, 0, &TID2)) {
		cout << "Ошибка создания потока" << GetLastError() << endl;
		system("pause");
		return -1;
	}
	
	system("pause");
	return 0;
}
