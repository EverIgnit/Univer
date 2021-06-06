#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>//include nedeed libraries
using namespace std;

int main() {
	// Definition
	HANDLE hFileMapping;
	HANDLE hEvent;
	LPCWSTR lEvent = L"Event"; 
	LPCWSTR lMapping = L"Mapping"; 
	LPTSTR buf;
	LPTSTR pathFile = L"file.txt";

	hEvent = OpenEvent(EVENT_ALL_ACCESS, FALSE, lEvent); //open event from name

	// Open file mapping by name
	hFileMapping = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"Mapping"); 
	if (!hFileMapping) {
		cout << GetLastError() << " Error on create file mapping" << endl;
		system("pause");
		return 1;
	}

	// Create map view of file
	buf = (LPTSTR)MapViewOfFile(hFileMapping, FILE_MAP_ALL_ACCESS, 0, 0, 0); 
	if (buf == NULL) {
		cout << GetLastError() << "Error" << endl;
		system("pause");
		return 1;
	}

	// Definition
	char* Result = new char; 
	cin.getline(Result, '\n');
	int count = 20;

	// Write in file mapping
	CopyMemory(&buf[count], Result, strlen(Result));

	// Unmap view of file
	UnmapViewOfFile(buf);

	// Set the event in alrm state
	SetEvent(hEvent);

	system("pause");
	return 0;
}

