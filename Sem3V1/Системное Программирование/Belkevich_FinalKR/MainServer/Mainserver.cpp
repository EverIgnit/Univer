#include <windows.h>
#include <iostream>
#pragma comment(lib, "WS2_32.lib")

using namespace std;

#define SERVER_PORT 23123
#define CLIENT 0
#define SERVER 1


//	!	!	!	!	!	!	!	!	!	!	!	!	!	!	!
// ��� ����������� �������� ����� �������� �������� ���� ��������
unsigned short n = 10;
//	!	!	!	!	!	!	!	!	!	!	!	!	!	!	!
char computerName[80];
char pipeName[80];
HANDLE hNamedPipe;
DWORD dwBytesRead;
char buff[256];
int sockAddrLen = sizeof(sockaddr_in); //��� accept
sockaddr_in saClient;
SOCKET serverSocket;
SOCKET* Clients = new SOCKET[n];

DWORD WINAPI AddClient(LPVOID param) {
	//�������� ��������
	int count;
	for (count = 0; count < n; count++) {
		Clients[count] = accept(serverSocket, //��������� ��������������� �����
			(SOCKADDR*)&saClient, //����� ������������ �� ������� ��������� ����������� ������
			&sockAddrLen); //����� ����������, � ������� ���������� ����� ��������� 
		if (Clients[count] == INVALID_SOCKET) {
			cerr << "������ ���������� " << WSAGetLastError() << endl;
			cin.get();
			return ;
		}
		else
			cout << "����������� ������� ������ �������" << endl;
	}
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	cout << "Enter Servername: ";
	cin.getline(computerName, 80);

	wsprintf(pipeName, "\\\\%s\\pipe\\MyPipe", computerName);  //����������� �������� ��� ������ � ������ ������

	if (!WaitNamedPipe(pipeName,     //����� ����� pipeName ����� �������� ��� ����������
		NMPWAIT_WAIT_FOREVER)) {
		cout << "The pipe doesn't exist or is already taken" << endl
			<< "Error: " << GetLastError() << endl;
		cin.get();
		return 0;
	}

	hNamedPipe = CreateFile(pipeName, GENERIC_READ, 0, NULL,/*security attributes*/OPEN_EXISTING, 0, /*attribute file*/NULL/*������������*/);  //����������� � ������

	if (hNamedPipe == INVALID_HANDLE_VALUE)
	{
		cerr << "Failed to connect to the pipe" << endl
			<< "Error: " << GetLastError() << endl;
		cin.get();
		system("pause");
		return 0;
	}
	else
		cout << "You have connected successfully\n";

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=

	//������������� ���������� WinSock
	WSADATA data; //���������, ������� ���������� ���������� � ���������� ���������� Windows Sockets 
	int res = WSAStartup(0x0202, /*����� ������� ������ ���������� WinSock, ������� ��������� ������������ */&data);
	if (res != 0) {
		cerr << "������ �������������: " << res;
		cin.get();
		return 0;
	}
	//�������� ������
	serverSocket = socket(AF_INET, /*IPv4*/SOCK_STREAM, /*c�����, ��������������� �� ����������*/IPPROTO_TCP/*TCP*/);

	if (serverSocket == INVALID_SOCKET) {
		cerr << "������ �������� ������" << WSAGetLastError() << endl;
		cin.get();
		return 0;
	}

	//������������� ��������� sockaddr_in
	sockaddr_in sa;
	sa.sin_family = AF_INET; // IPv4
	sa.sin_addr.S_un.S_addr = htonl(INADDR_ANY); //IP ����������, � �������� ����� ����������� �������� �����������
	sa.sin_port = htons(SERVER_PORT); // ����

	// ��������� ����� ������, �������� ���������� � ������ �����
	if (bind(serverSocket, /*����������� �����*/(SOCKADDR*)&sa, /* ����� ��������� �������, ����� ����� � �������� � ����������)*/sizeof(sa))== SOCKET_ERROR) {
		cerr << "������ ��������� ����� " << WSAGetLastError() << endl;
		cin.get();
		return 0;
	}

	//������������� ���������� ������
	if (listen(serverSocket, /*����� �������*/n) /*������������ ������ ������� ��������� �����������*/== SOCKET_ERROR) {
		cerr << "������ ������������� ������ " << WSAGetLastError() << endl;
		cin.get();
		return 0;
	}

	
	cout << "�������� ����������� ..." << endl;

	LPDWORD idT = 0;
	HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)AddClient, 0, 0, idT);
	if (!hThread) {
		cout << "error\n";
		system("pause");
		return 0;
	}

	while (buff != "Exit") {

		if (!ReadFile(hNamedPipe, buff, sizeof(buff), &dwBytesRead, NULL)) {  //������ ���������
			cerr << "Failed to read the message" << endl << "Error: " << GetLastError() << endl;
			CloseHandle(hNamedPipe);
			cin.get();
			system("pause");
			return 0;
		}

		for (int i = 0; i < n; i++) {
			if (send(Clients[i], buff, sizeof(buff), 0) == SOCKET_ERROR) {
				cerr << "������ �������� ������ " << WSAGetLastError() << endl;
				return 0;
			}
		}
	}

	//�������� ������ � ������
	DisconnectNamedPipe(hNamedPipe);
	CloseHandle(hNamedPipe);
	closesocket(serverSocket);
	WSACleanup();
	delete[]Clients;

	system("pause");
	return 0;
}
