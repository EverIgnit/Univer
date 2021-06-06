#include<iostream>
#include<Windows.h>
using namespace std;
string Msg(DWORD flags) {
	switch (flags) {
	case 0:
		return "Not inheritable, not safe from being closed\n";
	case HANDLE_FLAG_INHERIT:
		return "Inherit flag -set\n";
	case HANDLE_FLAG_PROTECT_FROM_CLOSE:
		return "Close Protection -set\n";
	default:
		return "No well-known messages has accureed\n";
	}
}
int main() {
	DWORD flags = 0, count = 0;

	if (!GetProcessHandleCount(GetCurrentProcess(), &count)) {
		cout << "Failed to get current process handle count\n";
		return 3;
	}
	printf("Current process has {%d} handles.\n", count);


	SECURITY_ATTRIBUTES sa;
	sa.bInheritHandle = FALSE;
	sa.lpSecurityDescriptor = FALSE;
	HANDLE mutex = CreateMutex(&sa, FALSE, FALSE);
	if (mutex == INVALID_HANDLE_VALUE) {
		cout << "Failed to create mutex\n";
		return 1;
	}
	cout << "Mutex created\n";

	if (!GetHandleInformation(mutex, &flags)) {
		cout << "Failed to get mutex info\n";
		return 2;
	}
	cout << "Mutex info:\t" << Msg(flags);
	SetHandleInformation(mutex, HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT);
	if (!GetHandleInformation(mutex, &flags)) {
		cout << "Failed to get mutex info (2nd time)\n";
		return 2;
	}
	cout << "Mutex info #2:\t" << Msg(flags);


	if (!GetProcessHandleCount(GetCurrentProcess(), &count)) {
		cout << "Failed to get current process handle count\n";
		return 3;
	}
	printf("Current process has {%d} handles.\n", count);
	return 0;
}