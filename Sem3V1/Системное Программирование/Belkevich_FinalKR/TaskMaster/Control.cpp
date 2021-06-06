#include <Windows.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	setlocale(0, "");

	HANDLE hNamedPipe;
	DWORD dwBytesRead;
	DWORD dwBytesWrite;
	char buff[256];

	SECURITY_ATTRIBUTES sa;
	SECURITY_DESCRIPTOR sd;

	// заполн€ем атрибуты безопасности, 
	// отключаем наследование дескрипторов

	sa.bInheritHandle = FALSE;
	sa.nLength = sizeof(sa);
	InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);
	SetSecurityDescriptorDacl(&sd, TRUE, NULL, FALSE); //устанавливаем доступ(разрешЄн всем)
	sa.lpSecurityDescriptor = &sd;   // созданный дескриптор используем в SECURITY_ATTRIBUTES

	hNamedPipe = CreateNamedPipe("\\\\.\\pipe\\MyPipe", // name pipe
		PIPE_ACCESS_OUTBOUND, // сервер пишет, а клиент читает данные
		PIPE_TYPE_MESSAGE | PIPE_WAIT, //data transfer mode
		1,//maximum number of channel instances
		0,//output buffer size
		0,//INPUT
		INFINITE,//CLIENT WAITING TIME
		&sa//security attributes
		);

	if (hNamedPipe == INVALID_HANDLE_VALUE) {
		cerr << "Failed to create the pipe" << endl
			<< "Error: " << GetLastError() << endl;
		cin.get();
		return 0;
	}

	cout << "Waiting for connection..." << endl;

	if (!ConnectNamedPipe(hNamedPipe,NULL  /* asynchronous*/)){
		cerr << "Failed to connect to the pipe" << endl
			<< "Error: " << GetLastError() << endl;
		CloseHandle(hNamedPipe);
		cin.get();
		system("pause");
		return 0;
	}
	else 
		cout << "The Client has connected" << endl;

	while (buff!="Exit") {
		cout << "¬ведите команду дл€ передачи клиентам\n";
		cin.getline(buff, sizeof(buff));

		if (!WriteFile(hNamedPipe, buff, sizeof(char) * strlen(buff) + 1, &dwBytesWrite, NULL)) {
			cerr << "Failed to write" << endl << "Error: " << GetLastError() << endl;
			CloseHandle(hNamedPipe);
			cin.get();
			system("pause");
			return 0;
		}
	}

	DisconnectNamedPipe(hNamedPipe);
	CloseHandle(hNamedPipe);
	system("pause");
	return 0;
}