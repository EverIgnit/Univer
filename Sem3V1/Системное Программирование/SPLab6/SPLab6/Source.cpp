#include "windows.h"
#include <iostream>

using namespace std;

int main() {
	setlocale(0, "");



	SetCurrentDirectory("C:\\Users\\1801080061\\Downloads");

	TCHAR* name = "C:\\Users\\1801080061\\Downloads\\SPLab6\\test.info";
	TCHAR* Name = "Text.txt";

	if (!CopyFile(name, Name, FALSE))
		cout << "������ ����������� �����." << endl;
	else
		cout << "����������� ���������." << endl;

	HANDLE hEndRead;

	hEndRead = CreateEvent(NULL, //attribures
		FALSE, //no need in ResetEvent to non-signal state
		FALSE, // non-signaled state
		NULL // Name
	);
	if (hEndRead == NULL)
	{
		return GetLastError();
		system("pause");
		return 0;
	}


	HANDLE hFile = CreateFile(name, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED/* to enable access to the file without waiting for another process to be finished | FILE_ATTRIBUTE_NORMAL*/, NULL);

	if (hFile == NULL) {
		cout << "������ �������� �����." << endl;
		system("pause");
		return 0;
	}
	else
		cout << "���� ������." << endl;

	TCHAR buffer[126];
	DWORD n, k;

	OVERLAPPED overlapped;
	SecureZeroMemory(&overlapped, sizeof(overlapped));
	overlapped.Offset = 271014;
	overlapped.hEvent = hEndRead;

	DWORD dwRet;
	ReadFile(hFile, buffer, sizeof(buffer), &n, &overlapped);
	dwRet = GetLastError();
	if (dwRet == ERROR_IO_PENDING)
		cout << "���� ��������." << endl;
	else
	{
		cout << "���� �� ���������� �����������. ��� ������:" << dwRet << endl;
		system("pause");
		return 0;
	}

	TCHAR* Name2 = "answer.txt";

	HANDLE hEndWrite;

	HANDLE hFile2 = CreateFile(Name2, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile2 == NULL)
		cout << "������ �������� �����." << endl;
	else
		cout << "���� ������." << endl;

	while (true) {
		if (WaitForSingleObject(overlapped.hEvent, INFINITE) == WAIT_OBJECT_0 && GetOverlappedResult(hFile, &overlapped, &n, TRUE) != 0)
			break;
		else
		{
			system("pause");
			return 0;
		}
	}


	if (!WriteFile(hFile2, buffer, n, &k, NULL)) {
		cout << "���� �� ���������. ��� ������:" << GetLastError() << endl;
		system("pause");
		return 0;
	}
	else {
		cout << "���� ���������." << endl;
	}

	CloseHandle(hFile);
	CloseHandle(hFile2);
	CloseHandle(hEndRead);

	system("pause");
	return 0;
}
