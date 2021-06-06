#include <iostream>
#include <windows.h>

using namespace std;

int main() {

	STARTUPINFO si;
	ZeroMemory (&si, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;

	TCHAR lpszAppName[] = L"C:\\Program Files\\Internet Explorer\\iexplore.exe";
		if (!CreateProcess(NULL, lpszAppName, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
			int error = GetLastError();
			cerr << "Create process failed with code: " << error << endl;
			system("pause");
			return -1;
		}
		
	system("pause");
	return 0;
}






/*
cout << pi.dwProcessId << endl;
cout << si.dwXSize << si.dwYSize << endl;
*/