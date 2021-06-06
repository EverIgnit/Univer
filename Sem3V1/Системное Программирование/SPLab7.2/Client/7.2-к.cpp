#include <windows.h>
#include <iostream>
#pragma comment(lib, "WS2_32.lib")

using namespace std;

#define SERVER_PORT 3012

char point[3];
char buff;

int receive(SOCKET clientSocket) {
	buff = '1';
	while (buff != NULL) {
		if (recv(clientSocket, &buff, sizeof(buff), 0) == SOCKET_ERROR) {
			cerr << "������ ������ ������ " << WSAGetLastError() << endl;
			cin.get();
			return 0;
		}
		if (atoi(&buff) == 5) {
			cout << "�� ��������!" << endl;
			system("pause");
			return 0;
		}
		if (atoi(&buff) == 4) {
			cout << "�� ���������!" << endl;
			system("pause");
			return 0;
		}
		if (atoi(&buff) == 8) {
			cout << "�����" << endl;
			system("pause");
			return 0;
		}
		if (atoi(&buff) == 9) {
			cout << "������������ ������. ���������� ������ �����." << endl << "> ";
			cin >> point;
			if (send(clientSocket, point, sizeof(point), 0) == SOCKET_ERROR) {
				cerr << "������ �������� ������ " << WSAGetLastError() << endl;
				cin.get();
				return 0;
			}
			receive(clientSocket);
		}
		else cout << buff;
	}
	return 1;
}

int main() {

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	cout << "����� ���������� � ���� \"��������-������\" " << endl;
	cout << "������� IP �������: ";
	char addr[20];
	cin.getline(addr, sizeof(addr));

	WSADATA data;
	int res = WSAStartup(MAKEWORD(2, 2), &data);
	SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (clientSocket == INVALID_SOCKET) {
		cout << "������ �������� ������." << WSAGetLastError() << endl;
		cin.get();
		return 0;
	}
	sockaddr_in sa;
	ZeroMemory(&sa, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_addr.S_un.S_addr = inet_addr(addr);
	sa.sin_port = htons(SERVER_PORT);

	if (connect(clientSocket, (SOCKADDR*)&sa, sizeof(sa)) == SOCKET_ERROR) {
		cerr << "������ �����������" << WSAGetLastError() << endl;
		cin.get();
		return 0;
	}
	else cout << "���������� �����������..." << endl;
	cout << "������� ���������� ������" << endl;
	char c;

	if (recv(clientSocket, &c, sizeof(c), 0) == SOCKET_ERROR) {
		cerr << "������ ������ ������ " << WSAGetLastError() << endl;
		cin.get();
		return 0;
	}

	if (atoi(&c) == 1) {
		while (true) {
			if (receive(clientSocket) == 0) return 0;

			cout << "��� ���" << endl;
			cin >> point;

			if (send(clientSocket, point, sizeof(point), 0) == SOCKET_ERROR) {
				cerr << "������ �������� ������ " << WSAGetLastError() << endl;
				cin.get();
				return 0;
			}

			receive(clientSocket);

			cout << endl;
			cout << "��� ����������" << endl;
		}
	}
	else if (atoi(&c) == 2) {
		while (true) {
			receive(clientSocket);
			cout << "��� ����������" << endl;

			receive(clientSocket);
			cout << "��� ���" << endl;
			cin >> point;

			if (send(clientSocket, point, sizeof(point), 0) == SOCKET_ERROR) {
				cerr << "������ �������� ������ " << WSAGetLastError() << endl;
				cin.get();
				return 0;
			}
		}

	}

	system("pause");
	return 0;
}