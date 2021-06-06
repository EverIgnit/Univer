#include<iostream>
#include<Windows.h>
using namespace std;
int main(int argc, char* argv[]) {
	HANDLE hProc = (HANDLE)atoi(argv[1]);
	char dataBuffer[] = "Changed priority of inheritable process to High.\n";

	cout << GetPriorityClass(hProc) << "\n";
	SetPriorityClass(hProc, HIGH_PRIORITY_CLASS);
	cout << GetPriorityClass(hProc) << "\n";
	if (!WriteFile(
		(HANDLE)atoi(argv[2]),
		dataBuffer,
		(DWORD)strlen(dataBuffer),
		NULL,
		NULL
	))
		printf("Error writing to file:\t%d\n", GetLastError());
	return 0;
}