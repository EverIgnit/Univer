#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Windows.h"
#include <stdio.h>
#include <stdlib.h>
#include "winbase.h"
#include <string>
using namespace std;

int main()
{
	setlocale(0, "");
	char mutex_buf[10];
	char maping_buf[10];
	
	cout << "Полученные дескрипторы:" << endl;
	GetEnvironmentVariable("Mutex", mutex_buf, sizeof(mutex_buf));
	HANDLE mutex = (HANDLE)atoi(mutex_buf);
	cout <<"Handle Mutex:"<< mutex << endl;

	GetEnvironmentVariable("Mapping", maping_buf, sizeof(maping_buf));
	HANDLE mapping = (HANDLE)atoi(maping_buf);
	cout << "Handle Mapping:" << mapping << endl;

	char* res = (char*)MapViewOfFile(mapping, FILE_MAP_WRITE, 0, 0, 0);
	
	string input;
	while (true)
	{
		WaitForSingleObject(mutex, INFINITE);
		cout << "Введите сообщение(введите <stop>, если хотите завершить процесс):" << endl;
		getline(cin, input);
		if (input == "stop")
			break;
		
		input +="\r\n";
		strcat(res, "Child:");
		strcat(res, input.c_str());
		ReleaseMutex(mutex);
	}
	ReleaseMutex(mutex);
	UnmapViewOfFile(res);
	CloseHandle(mutex);
	system("pause");
	return 0;
}