#include <iostream>
#include "Windows.h"

using namespace std;

int main() {
	HANDLE process = GetCurrentProcess();
	DWORD count;

	if (!GetProcessHandleCount(process, &count)) {
		cout << "Error: " << GetLastError() << endl;
		system("pause");
		return -1;
	}

	cout << count << endl;
	char path[] = "D:\\OS\\Test.txt";
	HANDLE hFile = CreateFile(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE){
		cout << "Error: " << GetLastError() << endl;
		system("pause");
		return -1;
	}

	DWORD dwFlags = HANDLE_FLAG_INHERIT;

	if (!GetHandleInformation(hFile, &dwFlags))
	{
		cout << "Error: " << GetLastError() << endl;
		system("pause");
		return -1;
	}

	BOOL HandInheritable = (0 != (dwFlags & HANDLE_FLAG_INHERIT));

	if (HandInheritable)
	{
		cout << "Handle inheritable" << endl;
	}
	else {
		cout << "Handle not inheritable" << endl;
	}

	cout << "Handles count: ";
	if (!GetProcessHandleCount(process, &count))
	{
		cout << "Error: " << GetLastError() << endl;
		system("pause");
		return -1;
	}

	cout << count << endl;

	dwFlags = 0;
	if (!GetHandleInformation(hFile, &dwFlags)) {	
		cout << "Error: " << GetLastError() << endl;
		system("pause");
		return -1;
	}

	HandInheritable = (0 != (dwFlags & HANDLE_FLAG_PROTECT_FROM_CLOSE));
	if (HandInheritable == true)
	{
		cout << "Handle protected from close" << endl;
	}
	else {
		cout << "Handle is not protected from close" << endl;
	}
	
	if (!SetHandleInformation(hFile, HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT))
	{
		cout << "Error: " << GetLastError() << endl;
		system("pause");
		return -1;
	}
	if (!GetHandleInformation(hFile, &dwFlags))
	{
		cout << "Error: " << GetLastError() << endl;
		system("pause");
		return -1;
	}

	HandInheritable = (0 != (dwFlags & HANDLE_FLAG_INHERIT));
	
	if (HandInheritable == true)
	{
		cout << "Handle inherited" << endl;
	}
	else {
		cout << "Handle is not inherited" << endl;
	}

	system("pause");
	return 0;
}