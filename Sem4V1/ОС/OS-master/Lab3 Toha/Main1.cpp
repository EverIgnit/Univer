#include<iostream>
#include<Windows.h>
using namespace std;
int main() {
	DWORD flags = 0, count = 0;

	if (!GetProcessHandleCount(GetCurrentProcess(), &count)) {
		cout << "Failed to get current process handle count\n";
		return 3;
	}
	cout << "Current process has {" << count << "} handles.\n";


	SECURITY_ATTRIBUTES sa;
	sa.bInheritHandle = FALSE;
	sa.lpSecurityDescriptor = FALSE;
	HANDLE mutex = CreateMutex(&sa, FALSE, FALSE);
	if (mutex == INVALID_HANDLE_VALUE) {
		cout << "Failed to create mutex\n";
		return 1;
	}
	cout << "Mutex created.";

	if (!GetHandleInformation(mutex, &flags)) {
		cout << "Failed to get mutex info\n";
		return 2;
	}
	cout << "Mutex info:\n";
	if (flags == 0) {
		cout << "Not inheritable, not safe from being closed\n";
	}
	if (flags == HANDLE_FLAG_INHERIT) {
		cout << "Inherit flag -set\n";
	}
	if (flags == HANDLE_FLAG_PROTECT_FROM_CLOSE) {
		cout << "Close Protection -set\n";
	}
	SetHandleInformation(mutex, HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT);
	if (!GetHandleInformation(mutex, &flags)) {
		cout << "Failed to get mutex info (2nd time)\n";
		return 2;
	}
	cout << "Mutex info #2:\n";
	if (flags == 0) {
		cout << "Not inheritable, not safe from being closed\n";
	}
	if (flags == HANDLE_FLAG_INHERIT) {
		cout << "Inherit flag -set\n";
	}
	if (flags == HANDLE_FLAG_PROTECT_FROM_CLOSE) {
		cout << "Close Protection -set\n";
	}


	if (!GetProcessHandleCount(GetCurrentProcess(), &count)) {
		cout << "Failed to get current process handle count\n";
		return 3;
	}
	cout << "Current process has {" << count << "} handles.\n";

	return 0;
}