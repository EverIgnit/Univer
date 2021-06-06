#include <iostream>
#include <Windows.h>
using namespace std;
#define BUF_SIZE 500

TCHAR nameOfMapping[] = TEXT("Mapping");
TCHAR nameOfEvent[] = TEXT("Event");
string str;//message
int main() {
	setlocale(0, "");
	STARTUPINFO si;
	si.cb = sizeof(si);
	GetStartupInfo(&si);
	PROCESS_INFORMATION pi;
	
	HANDLE file = CreateFile(
		L"text.txt",
		GENERIC_READ | GENERIC_WRITE,
		NULL,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (file == INVALID_HANDLE_VALUE) {
		cout << "������ �������� �����!" << endl;
		return 0;
	}
	else cout << "���� ������:" << file << endl;


	HANDLE hMapping = CreateFileMapping(
		file,
		NULL,
		PAGE_READWRITE,
		0,
		BUF_SIZE,
		nameOfMapping
	);
	if (!hMapping)
	{
		cout << "CreateFileMapping file error(fileMapping3): " << GetLastError() << endl;
		CloseHandle(file);
		system("pause");
		return 0;
	}
	cout << "�������� ����������� �������:" << hMapping << endl;

	HANDLE hEvent = CreateEvent
	(
		NULL,			// ������� ������
		TRUE,			// ��� ������ TRUE - ������
		FALSE,			// ��������� ��������� TRUE - ����������
		nameOfEvent		// ��� �������
	);
	if (hEvent == NULL)
	{
		cout << "������� �� �������" << GetLastError() << endl;
		CloseHandle(file);
		CloseHandle(hMapping);
		return 0;
	}
	else cout << "������� �������:"<<hEvent << endl;

	TCHAR comLine[] = TEXT("user");

	bool Procces = CreateProcess(NULL, comLine, NULL, NULL, FALSE,CREATE_NEW_CONSOLE, NULL, NULL, &(si), &(pi));
	if (Procces)	cout << "������� ������� ������" << endl;
	else			cout << "������� �� ������" << endl;

	char* itog = (char*)MapViewOfFile(hMapping, FILE_MAP_WRITE, 0, 0, 0);
		
	WaitForSingleObject(hEvent, INFINITE);
	cout << "������� ��������� " << endl;	cin >> str;
	str += itog;
	memcpy(itog, str.c_str(), str.size());
	cout << "������������� ������ ���������!!!" << endl;
	//close
	UnmapViewOfFile(itog);
	CloseHandle(file);
	CloseHandle(hMapping);
	CloseHandle(hEvent);

	cout << "������� �������� ���������������� ���������" << endl;
	WaitForSingleObject(pi.hProcess, INFINITE);// ���������� ����� ���������� �������� ��������
	//close
	CloseHandle(pi.hProcess);//�������� ��������
	CloseHandle(pi.hThread);
	system("pause");
	return 0;
}