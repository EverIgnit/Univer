#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;

int main() {
	//task proc data
	STARTUPINFO siTaskProc;
	PROCESS_INFORMATION piTaskProc;
	ZeroMemory(&siTaskProc, sizeof(siTaskProc));
	ZeroMemory(&piTaskProc, sizeof(piTaskProc));

	SECURITY_ATTRIBUTES fileSA;
	fileSA.bInheritHandle = TRUE;
	fileSA.lpSecurityDescriptor = NULL;

	//task file
	HANDLE file = CreateFile(L"No2.txt",
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		&fileSA,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	//write file creation
	char dataBuffer[] = "Created No2.txt.\n";
	DWORD dwBytesToWrite = (DWORD)strlen(dataBuffer);
	if (!WriteFile(
		file,
		dataBuffer,
		dwBytesToWrite,
		NULL,
		NULL
	))
	{
		cout << "Error writing to file (initial):" << GetLastError() << "\n";
	}

	if (file == INVALID_HANDLE_VALUE)
	{
		cerr << "Error creating file: " << GetLastError() << "\n";
		return 1;
	}

	//task proc
	if (!CreateProcess(
		L"D:\\Programms\\Notepad++\\notepad++.exe", //process
		NULL,						//command line
		&fileSA,					//process attr
		FALSE,						//thread attr
		TRUE,						//inheritable
		NULL,						//creation flags
		NULL,						//environment
		NULL,						//current dir
		&siTaskProc,				//startup info
		&piTaskProc))				//process info
	{
		cerr << "Error creating task process:" << GetLastError() << "\n";
		return 2;
	}

	//write task process
	char dataBuffer1[] = "Created task process (Notepad++).\n";
	dwBytesToWrite = (DWORD)strlen(dataBuffer1);
	if (!WriteFile(
		file,
		dataBuffer1,
		dwBytesToWrite,
		NULL,
		NULL
	))
	{
		cout << "Error writing to file (task process):" << GetLastError() << "\n";
	}


	//CHILD PROCESS DATA
	STARTUPINFO childSI;
	PROCESS_INFORMATION childPI;
	ZeroMemory(&childPI, sizeof(childPI));
	ZeroMemory(&childSI, sizeof(childSI));

	SECURITY_ATTRIBUTES childSA;
	childSA.bInheritHandle = TRUE;
	childSA.lpSecurityDescriptor = NULL;

	//
	DWORD dwProc = (DWORD)piTaskProc.hProcess, dwFile = (DWORD)file;
	char procHandle[sizeof(DWORD)];
	//char procHandle[sizeof(int)];
	sprintf_s(procHandle, "%d", dwProc);
	char fileHandle[sizeof(DWORD)];
	//char fileHandle[sizeof(int)];
	sprintf_s(fileHandle, "%d", dwFile);

	//HANDLE handProc = (HANDLE)dwProc, handFile = (HANDLE)dwFile;

	std::string str("D:\\Projects\\InProgress\\Os\\Lab3\\Debug\\No2_Child.exe ");
	str += procHandle + std::string(" ") + fileHandle;
	const char* cstr = str.c_str();

	//create child process
	if (!CreateProcess(
		NULL,
		(LPWSTR)cstr,
		&childSA,
		NULL,
		TRUE,
		/*DEBUG_PROCESS*/NULL,
		NULL,
		NULL,
		&childSI,
		&childPI
	))
	{
		cerr << "Error creating child process: " << GetLastError() << "\n";
		return 4;
	}

	//write child process
	char dataBuffer2[] = "Created Child Process.\n";
	dwBytesToWrite = (DWORD)strlen(dataBuffer2);
	if (!WriteFile(
		file,
		dataBuffer2,
		dwBytesToWrite,
		NULL,
		NULL
	))
	{
		cout << "Error writing to file (child):" << GetLastError() << "\n";
	}
	WaitForSingleObject(childPI.hProcess, INFINITE);

	char dataBuffer3[] = "File handle closed.\n";
	dwBytesToWrite = (DWORD)strlen(dataBuffer3);
	if (!WriteFile(
		file,
		dataBuffer3,
		dwBytesToWrite,
		NULL,
		NULL
	))
	{
		cout << "Error writing to file (closed handle):" << GetLastError() << "\n";
	}
	CloseHandle(file);

	return 0;
}