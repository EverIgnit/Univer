#include <iostream>
#include <windows.h>

using namespace std;

int main() {

	STARTUPINFO si;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;
	ZeroMemory(&pi,sizeof(PROCESS_INFORMATION));

	TCHAR lpszAppName[] = L"C:\\Users\\1801080061\\Downloads\\361_ideaIU-2019.1.2.exe";
	if (!CreateProcess(lpszAppName, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
		int error = GetLastError();
		cerr << "Create process failed with code: " << error << endl;
		system("pause");
		return -1;
	}
	system("pause");
	return 0;
}