#include <iostream>
#include <windows.h>

using namespace std;

int main() {

	STARTUPINFO si;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;
	//ShellExecute(NULL, "open", "Notepad lab2.txt", NULL, NULL, SW_SHOWNORMAL);
	TCHAR lpszAppName[] = "Notepad lab2.txt";
	if (!CreateProcess(NULL, lpszAppName, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
		int error = GetLastError();
		cerr << "Create process failed with code: " << error << endl;
		system("pause");
		return -1;
	}
	system("pause");
	return 0;
}