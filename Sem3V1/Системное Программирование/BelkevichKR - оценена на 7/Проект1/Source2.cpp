#include <iostream>
#include <Windows.h>
#include <TCHAR.H>
using namespace std;
int main() {
	setlocale(0, "");

	bool a;
	cout << "ÂÍÈÌÀÍÈÅ! ×ÒÎÁÛ ÓÂÈÄÅÒÜ ÐÅÇÓËÜÒÀÒ ÂÛÏÎËÍÅÍÈß ÏÐÎÃÐÀÌÌÛ, \nÓÊÀÆÈÒÅ Â ÔÓÍÊÖÈÈ SetCurrentDirectory\nÊÎÐÐÅÊÒÍÛÉ ÏÓÒÜ Ê ÔÀÉËÓ Ñ ÍÀÇÂÀÍÈÅÌ CompressMe.txt\nÎòêðûòü 7z?\n";
	cin >> a;
	STARTUPINFO si;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;
	SetCurrentDirectory(L"C:\\Users\\1801080061\\Downloads");
	TCHAR AppName[] = L"C:\\Program Files (x86)\\7-Zip\\7z.exe a -sfx7z.sfx archive(sfx_version).exe CompressMe.txt -m1=LZMA";
	//L"C:\\Program Files\\7-Zip\\7z.exe a -sfx7z.sfx 1_1.exe C:\\Users\\1801080061\\Downloads\\BelkevichKR\\CompressMe.txt -m1=LZMA";
	//L"C:\\Program Files (x86)\\7-Zip\\7zFM.exe a C:\\Users\\1801080061\\Documents\\CompressMe.txt C:\\Users\\1801080061\\Documents\\CompressMe.zip -m1=LZMA2";

	if (CreateProcess(NULL, AppName, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
		DWORD exitcode;
		WaitForSingleObject(pi.hProcess, INFINITE) == WAIT_OBJECT_0;
		GetExitCodeProcess(pi.hProcess, &exitcode);
		cout << "Êîä ñòàòóñà:\t" << exitcode << endl;
	}
	else
		cout << "Error: " << GetLastError() << std::endl;
	system("pause");
	return 0;
}