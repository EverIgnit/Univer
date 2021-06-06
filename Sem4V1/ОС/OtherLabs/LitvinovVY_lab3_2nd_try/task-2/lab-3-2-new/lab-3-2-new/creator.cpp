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
		cout << "Ошибка создания файла!" << endl;
		return 0;
	}
	else cout << "Файл создан:" << file << endl;


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
	cout << "Файловое отображение создано:" << hMapping << endl;

	HANDLE hEvent = CreateEvent
	(
		NULL,			// атрибут защиты
		TRUE,			// тип сброса TRUE - ручной
		FALSE,			// начальное состояние TRUE - сигнальное
		nameOfEvent		// имя обьекта
	);
	if (hEvent == NULL)
	{
		cout << "Событие не создано" << GetLastError() << endl;
		CloseHandle(file);
		CloseHandle(hMapping);
		return 0;
	}
	else cout << "Событие создано:"<<hEvent << endl;

	TCHAR comLine[] = TEXT("user");

	bool Procces = CreateProcess(NULL, comLine, NULL, NULL, FALSE,CREATE_NEW_CONSOLE, NULL, NULL, &(si), &(pi));
	if (Procces)	cout << "Процесс успешно создан" << endl;
	else			cout << "Процесс не создан" << endl;

	char* itog = (char*)MapViewOfFile(hMapping, FILE_MAP_WRITE, 0, 0, 0);
		
	WaitForSingleObject(hEvent, INFINITE);
	cout << "Введите сообщение " << endl;	cin >> str;
	str += itog;
	memcpy(itog, str.c_str(), str.size());
	cout << "Окончательная запись произошла!!!" << endl;
	//close
	UnmapViewOfFile(itog);
	CloseHandle(file);
	CloseHandle(hMapping);
	CloseHandle(hEvent);

	cout << "Ожидаем закрытие пользовательской программы" << endl;
	WaitForSingleObject(pi.hProcess, INFINITE);// дожидаемся когда произойдет закрытие процесса
	//close
	CloseHandle(pi.hProcess);//закрытие процесса
	CloseHandle(pi.hThread);
	system("pause");
	return 0;
}