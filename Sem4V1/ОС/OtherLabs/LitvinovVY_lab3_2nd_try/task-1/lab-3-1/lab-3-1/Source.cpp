#include<Windows.h>
#include<iostream>
#include<string.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "");
	DWORD infMutex = 0, countOfHandles = 0;//горбатый стить JS xD

	//Получает количество открытых дескрипторов, принадлежащих указанному процессу.
	if (!GetProcessHandleCount(GetCurrentProcess(), &countOfHandles)) {
		cout << "Не удалось получить текущий дескриптор процесса" << endl;
		return 0;
	}
	cout << "Текущий процесс имеет[" << countOfHandles <<"] дескрипторов" << endl;
	//атрибуты безопасности для мьютекса
	SECURITY_ATTRIBUTES sa;
	sa.bInheritHandle = FALSE;//Логическое значение-наследуется ли возвращаемый дескриптор при создании нового процесса? 
	sa.lpSecurityDescriptor = NULL;//контролирует доступ к объекту
	//NULL - защита по-умолчанию

	HANDLE mutex = CreateMutex(&sa, FALSE, FALSE);
	if (mutex == INVALID_HANDLE_VALUE) {
		cout << "Ошибка создания мьютекса!" << endl;
		return 0;
	}
	cout << "Мьютекс создан!" << endl;
	//получаю информуцию мьютекса
	if (!GetHandleInformation(mutex, &infMutex)) {
		cout << "Ошибка получения информации мьютекса" << endl;
		return 0;
	}
	cout << "Получили информацию мьютекса(смотрите ниже)" << endl;
	if (infMutex == 0)									cout << "Не наследуется, для открытия не безопасно!" << endl;
	//Если этот флажок установлен, дочерний процесс, 
	//созданный функцией CreateProcess с параметром bInheritHandles 
	//установленным в значение ИСТИНА (TRUE) наследует дескриптор объекта. 
	if (infMutex == HANDLE_FLAG_INHERIT)				cout << "Дочерний процесс наследует дескриптор объекта" << endl;
	//Если этот флажок установлен, вызов функции CloseHandle не будет закрывать дескриптор объекта.
	if (infMutex == HANDLE_FLAG_PROTECT_FROM_CLOSE)		cout << "Защита закрытия имеется" << endl;

	SetHandleInformation(mutex, HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT);
	//получаю информацию мьютекса второй раз
	if (!GetHandleInformation(mutex, &infMutex)) {
		cout << "Не удалось получить информацию мьютекса(2)" << endl;
		return 0;
	}
	cout << "Получили информацию мьютекса(2)(смотрите ниже)" << endl;

	if (infMutex == 0)									cout << "Не наследуется, для открытия не безопасно!" << endl;
	if (infMutex == HANDLE_FLAG_INHERIT)				cout << "Дочерний процесс наследует дескриптор объекта" << endl;
	if (infMutex == HANDLE_FLAG_PROTECT_FROM_CLOSE)	cout << "Защита закрытия имеется" << endl;

	//Получает количество открытых дескрипторов, принадлежащих указанному процессу.
	if (!GetProcessHandleCount(GetCurrentProcess(), &countOfHandles)) {
		cout << "Не удалось получить текущий дескриптор процесса" << endl;
		return 0;
	}
	cout << "Текущий процесс имеет[" << countOfHandles << "] дескрипторов" << endl;
	system("pause");
	return 0;
}