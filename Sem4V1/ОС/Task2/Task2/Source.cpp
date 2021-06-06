#include<iostream>
#include<Windows.h>
using namespace std;
int main(int argc, char* argv[]) {
	HANDLE hProc = (HANDLE)atoi(argv[1]);

	cout << GetPriorityClass(hProc) << "\n";
	SetPriorityClass(hProc, HIGH_PRIORITY_CLASS);
	cout << GetPriorityClass(hProc) << "\n";

	string s = "Changed priority of inheritable process to High.\n";
	if (!WriteFile((HANDLE)atoi(argv[2]), s.c_str(), (DWORD)strlen(s.c_str()), NULL, NULL))
		printf("Error writing to file:\t%d\n", GetLastError());
	return 0;
}