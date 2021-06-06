#include <iostream>
#include "windows.h"

using namespace std;

BOOL WINAPI DllMain(HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved) {
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH: // загрузка DLL 
		break;
	case DLL_THREAD_ATTACH: // создание потока 
		break;
	case DLL_THREAD_DETACH: // завершение потока 
		break;
	case DLL_PROCESS_DETACH: // отключение DLL 
		break;
	}
	return TRUE;
}

extern "C" __declspec(dllexport) char Message[] = "Hello,World!";

// extern "C" __declspec(dllexport) int Number = 0;

extern "C" __declspec(dllexport) void SayMessage(char* message) {
	cout << "DLL say> " << message << endl;
	return;
}

/*
extern "C" __declspec(dllexport) int SayNumber(int message) {
	cout << "DLL say> " << message << endl;
	return 1;
}
*/

/* 
	__declspec(dllexport) - exported functions or data
	extern "C" - disable the decorating names
	*/