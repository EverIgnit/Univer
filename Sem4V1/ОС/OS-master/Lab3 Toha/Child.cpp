#include<iostream>
#include<Windows.h>
using namespace std;
int main(int argc, char* argv[]) {
	DWORD dwProc = atoi(argv[1]);
	DWORD dwFile = atoi(argv[2]);
	HANDLE hProc = (HANDLE)dwProc;
	HANDLE hFile = (HANDLE)dwFile;
	char dataBuffer[] = "Changed priority of inheritable process to High.\n";
	DWORD dwBytesToWrite = (DWORD)strlen(dataBuffer);

	cout << GetPriorityClass(hProc) << "\n";
	//cout << "Changing process priority to High\n";
	SetPriorityClass(hProc, HIGH_PRIORITY_CLASS);
	cout << GetPriorityClass(hProc) << "\n";

	/*
	cout << "argc: " << argc << "\n";
	for (int i = 0; i < argc; i++) {
		cout  << "argv[" << i << "]:" << argv[i] << "\n";
	}
	cout << hProc << "<-(proc) dword (file)-> " << hFile << "\n";
	cout << (HANDLE)hProc << "<-proc (Handle) file-> " << (HANDLE)hFile << "\n";
*/
	if (!WriteFile(
		hFile,
		dataBuffer,
		dwBytesToWrite,
		NULL,
		NULL
	))
	{
		cout << "Error writing to file:" << GetLastError() << "\n";
	}
	return 0;
}