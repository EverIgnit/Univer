#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

int main() {
	// Definition
	HANDLE hFileMapping; 
	HANDLE hEvent; 
	HANDLE hFile;
	LPCTSTR buf; 
	LPTSTR pathFile = L"file.txt";

	// Define security attributes
	SECURITY_ATTRIBUTES sa;
	sa.bInheritHandle = false; // Not inherit handle
	sa.lpSecurityDescriptor = NULL; // Not security of handle
	sa.nLength = sizeof(SECURITY_ATTRIBUTES); // Memory allocation

	// Create Event in not a signal state
	hEvent = CreateEvent(&sa, TRUE, FALSE, L"Event"); 

	// Open File
	hFile = CreateFile(pathFile, GENERIC_READ | GENERIC_WRITE, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		cout << "Failed to open file. Code: " << GetLastError() << endl;
		system("pause");
		return 1;
	}

	// Create a mapping of openning file
	hFileMapping = CreateFileMapping(hFile, &sa, PAGE_READWRITE, 0, MAX_PATH, L"Test"); 
	if (!hFileMapping) {
		cout << GetLastError()<<" Error on create file mapping" << endl;
		system("pause");
		return 1;
	}

	// Create map view of file
	buf = (LPCTSTR)MapViewOfFile(hFileMapping, FILE_MAP_ALL_ACCESS, 0, 0, 0); 
	if (buf == NULL) {
		cout << GetLastError() << "Error" << endl;
		system("pause");
		return 1;
	}

	// Defition
	char* Result = new char;
	cin.getline(Result, '\n');

	// Write in file mapping
	CopyMemory((LPVOID)buf, Result, strlen(Result));

	// Wait while Event go to alarm state
	WaitForSingleObject(hEvent, INFINITE);
	cout << "all write" << endl;

	// Finish program
	UnmapViewOfFile(buf);
	CloseHandle(hFileMapping);
	CloseHandle(hFile);
	CloseHandle(hEvent);

	system("pause");
	return 0;
}

