#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Windows.h"
#include <stdio.h>
#include <stdlib.h>
#include "winbase.h"
#include <string>
#include <conio.h>
using namespace std;

int main() 
{
	setlocale(0, "");
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle = TRUE; 
	sa.lpSecurityDescriptor = NULL;

	STARTUPINFO si;
	si.cb = sizeof(si);
	GetStartupInfo(&si);
	PROCESS_INFORMATION pi;

	HANDLE mutex, file;
	mutex = CreateMutex(&sa, FALSE, NULL);
	if (mutex == NULL) {
		cout << "Мьютекс не создан. Ошибка: " << GetLastError() << endl;
		return 0;
	}

	cout << "Мьютекс был успешно создан " << mutex << endl;
	
	file = CreateFile("text.txt", GENERIC_READ | GENERIC_WRITE, NULL, &sa, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (file == INVALID_HANDLE_VALUE) {
		cout << "Ошибка создания файла!" << endl;
		return 1;
	}
	cout << "Файл создан "<<file << endl;

	HANDLE mapping = CreateFileMapping(file, &sa, PAGE_READWRITE, 0, 500, TEXT("Mapping"));
	if (!mapping)
	{
		cout << "CreateFileMapping file error: " << GetLastError() << endl;
		system("pause");
		return 1;
	}
	cout << "Файловое отображение создано " << mapping << endl;

	char char_mutex[10];
	_itoa((int)mutex, char_mutex, 10);

	char char_mapping[10];
	_itoa((int)mapping, char_mapping, 10);

	if (SetEnvironmentVariable(TEXT("Mutex"), char_mutex) != 0)
		cout << "Дескриптор Mutex передан!" << endl;
	else cout << "Не удалось передать дескриптор Mutex" << endl;
		
	if(SetEnvironmentVariable(TEXT("Mapping"), char_mapping) != 0)
	cout << "Дескриптор Mapping передан!" << endl;
	else cout << "Не удалось передать дескриптор Mapping" << endl;
	
	bool Procces = CreateProcess("D:\\OS\\Labs\\Lab_3\\server\\Debug\\client.exe",NULL, NULL, NULL, TRUE,
		CREATE_NEW_CONSOLE, NULL, NULL, &(si), &(pi));

	if (Procces)
		cout << "Дочерний процесс был создан" << endl;
	else
	cout << "Дочерний процесс не создан. Ошибка: " << GetLastError() << endl;

	char* res = (char*) MapViewOfFile(mapping, FILE_MAP_WRITE, 0, 0, 0);
	while (true)
	{
		string input;
		WaitForSingleObject(mutex, INFINITE);
		cout << "Введите сообщение(введите <stop>, если хотите завершить процесс):" << endl;
		getline(cin,input);
		if (input == "stop")
			break;
		
		input +="\r\n";
		strcat(res,"Parent:");
		strcat(res, input.c_str());
		cout << res;
		ReleaseMutex(mutex);
	}
	ReleaseMutex(mutex);
	UnmapViewOfFile(res);
	CloseHandle(file);
	CloseHandle(mutex);
	system("pause");
	return 0;
}