#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;

int main() {
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	SECURITY_ATTRIBUTES sa;
	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = NULL;

	HANDLE hFile = CreateFile(L"Task2.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, &sa, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	string s = "I've just born!\n";
	if (!WriteFile(hFile, s.c_str(), (DWORD)strlen(s.c_str()), NULL, NULL))
		printf("Error writing to file (initial):\t%d\n", GetLastError());

	if (hFile == INVALID_HANDLE_VALUE)
	{
		cerr << "Error creating file: " << GetLastError() << "\n";
		return 1;
	}

	if (!CreateProcess(L"C:\\Windows\\system32\\notepad.exe", NULL, &sa, FALSE, TRUE, NULL, NULL, NULL, &si, &pi))
	{
		cerr << "Error creating task process:" << GetLastError() << "\n";
		return 2;
	}

	s = "Created task process Notepad.\n";
	if (!WriteFile(hFile, s.c_str(), (DWORD)strlen(s.c_str()), NULL, NULL))
		printf("Error writing to file (task process):\t%d\n", GetLastError());


	ZeroMemory(&pi, sizeof(pi));
	ZeroMemory(&si, sizeof(si));
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = NULL;

	char procHandle[sizeof(DWORD)];
	sprintf_s(procHandle, "%d", (DWORD)pi.hProcess);

	char fileHandle[sizeof(DWORD)];
	sprintf_s(fileHandle, "%d", (DWORD)hFile);

	string str = "F:\\Documents\\Ó÷¸áà\\ÎÑ\\Task2\\Debug\\Task2.exe ";
	str += procHandle + string(" ") + fileHandle;


	if (!CreateProcess(NULL, (LPWSTR)str.c_str(), &sa, NULL, TRUE, NULL, NULL, NULL, &si, &pi))
	{
		cerr << "Error creating child process: " << GetLastError() << "\n";
		return 4;
	}

	s = "Created Child Process.\n";
	if (!WriteFile(hFile, s.c_str(), (DWORD)strlen(s.c_str()), NULL, NULL))
		printf("Error writing to file (child):\t%d\n", GetLastError());
	WaitForSingleObject(pi.hProcess, INFINITE);

	s = "File handle closed.\n";
	if (!WriteFile(hFile, s.c_str(), (DWORD)strlen(s.c_str()), NULL, NULL))
		printf("Error writing to file (closed handle):\t%d\n", GetLastError());

	CloseHandle(hFile);
	return 0;
}