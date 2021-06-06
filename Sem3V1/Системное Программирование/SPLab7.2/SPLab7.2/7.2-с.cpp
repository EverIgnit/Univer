#include <windows.h>
#include <iostream>
#pragma comment(lib, "WS2_32.lib")

using namespace std;

#define SERVER_PORT 3012
#define CLIENT 0
#define SERVER 1

int turns = 0;

char fNick[20];
char sNick[20];
char finishMessage[34] = "3";

char field[] = {
	' ', ' ', '1', ' ', '2', ' ', '3', '\n',
	'1', ' ', '_', ' ', '_', ' ', '_', '\n',
	'2', ' ', '_', ' ', '_', ' ', '_', '\n',
	'3', ' ', '_', ' ', '_', ' ', '_', ' ', '\n', '\0' };

int numField[3][3] = {
	{ 0, 0, 0 },
	{ 0, 0, 0 },
	{ 0, 0, 0 }
};

int redrawField(int a, int player) {
	if (a == 11 || a == 12 || a == 13 ||
		a == 21 || a == 22 || a == 23 ||
		a == 31 || a == 32 || a == 33) {
		switch (a) {
		case 11:
			switch (player) {
			case CLIENT:
				if (numField[0][0] == 0) {
					field[10] = 'O';
					numField[0][0] = 1;
				}
				else 
					return 9;
				break;
			case SERVER:
				if (numField[0][0] == 0) {
					field[10] = 'X';
					numField[0][0] = 2;
				}
				else 
					return 9;
				break;
			default:
				field[10] = '?';
				break;
			}
			turns++;
			break;
		case 12:
			switch (player) {
			case CLIENT:
				if (numField[0][1] == 0) {
					field[12] = 'O';
					numField[0][1] = 1;
				}
				else 
					return 9;
				break;
			case SERVER:
				if (numField[0][1] == 0) {
					field[12] = 'X';
					numField[0][1] = 2;
				}
				else 
					return 9;
				break;
			default:
				field[12] = '?';
				break;
			}
			turns++;
			break;
		case 13:
			switch (player) {
			case CLIENT:
				if (numField[0][2] == 0) {
					field[14] = 'O';
					numField[0][2] = 1;
				}
				else 
					return 9;
				break;
			case SERVER:
				if (numField[0][2] == 0) {
					field[14] = 'X';
					numField[0][2] = 2;
				}
				else 
					return 9;
				break;
			default:
				field[14] = '?';
				break;
			}
			turns++;
			break;
		case 21:
			switch (player) {
			case CLIENT:
				if (numField[1][0] == 0) {
					field[18] = 'O';
					numField[1][0] = 1;
				}
				else 
					return 9;
				break;
			case SERVER:
				if (numField[1][0] == 0) {
					field[18] = 'X';
					numField[1][0] = 2;
				}
				else
					return 9;
				break;
			default:
				field[18] = '?';
				break;
			}
			turns++;
			break;
		case 22:
			switch (player) {
			case CLIENT:
				if (numField[1][1] == 0) {
					field[20] = 'O';
					numField[1][1] = 1;
				}
				else 
					return 9;
				break;
			case SERVER:
				if (numField[1][1] == 0) {
					field[20] = 'X';
					numField[1][1] = 2;
				}
				else 
					return 9;
				break;
			default:
				field[20] = '?';
				break;
			}
			turns++;
			break;
		case 23:
			switch (player) {
			case CLIENT:
				if (numField[1][2] == 0) {
					field[22] = 'O';
					numField[1][2] = 1;
				}
				else
					return 9;
				break;
			case SERVER:
				if (numField[1][2] == 0) {
					field[22] = 'X';
					numField[1][2] = 2;
				}
				else 
					return 9;
				break;
			default:
				field[22] = '?';
				break;
			}
			turns++;
			break;
		case 31:
			switch (player) {
			case CLIENT:
				if (numField[2][0] == 0) {
					field[26] = 'O';
					numField[2][0] = 1;
				}
				else 
					return 9;
				break;
			case SERVER:
				if (numField[2][0] == 0) {
					field[26] = 'X';
					numField[2][0] = 2;
				}
				else
					return 9;
				break;
			default:
				field[26] = '?';
				break;
			}
			turns++;
			break;
		case 32:
			switch (player) {
			case CLIENT:
				if (numField[2][1] == 0) {
					field[28] = 'O';
					numField[2][1] = 1;
				}
				else
					return 9;
				break;
			case SERVER:
				if (numField[2][1] == 0) {
					field[28] = 'X';
					numField[2][1] = 2;
				}
				else 
					return 9;
				break;
			default:
				field[28] = '?';
				break;
			}
			turns++;
			break;
		case 33:
			switch (player) {
			case CLIENT:
				if (numField[2][2] == 0) {
					field[30] = 'O';
					numField[2][2] = 1;
				}
				else
					return 9;
				break;
			case SERVER:
				if (numField[2][2] == 0) {
					field[30] = 'X';
					numField[2][2] = 2;
				}
				else 
					return 9;
				break;
			default:
				field[30] = '?';
				break;
			}
			turns++;
			break;
		default:
			break;
		}
	}
	else 
		return 9;
	if (turns == 9) 
		return 8;
	else
		return 0;
}

bool isFinish() {
	for (int i = 0; i < 3; i++) {
		if (numField[i][1] == numField[i][0] && numField[i][1] == numField[i][2]) {
			if (numField[i][1] == 1) {
				finishMessage[0] = '5'; 
				return true;
			}
			if (numField[i][1] == 2) {
				finishMessage[0] = '4'; 
				return true;
			}
		}
	}
	for (int j = 0; j < 3; j++) {
		if (numField[1][j] == numField[0][j] && numField[1][j] == numField[2][j]) {
			if (numField[1][j] == 1) {
				finishMessage[0] = '5'; 
				return true;
			}
			if (numField[1][j] == 2) {
				finishMessage[0] = '4'; 
				return true;
			}
		}
	}
	if (numField[1][1] == numField[0][0] && numField[1][1] == numField[2][2]) {
		if (numField[1][1] == 1) {
			finishMessage[0] = '5'; 
			return true;
		}
		if (numField[1][1] == 2) {
			finishMessage[0] = '4'; 
			return true;
		}
	}
	if (numField[1][1] == numField[0][2] && numField[1][1] == numField[2][0]) {
		if (numField[1][1] == 1) {
			finishMessage[0] = '5';
			return true;
		}
		if (numField[1][1] == 2) {
			finishMessage[0] = '4'; 
			return true;
		}
	}
	return 0;
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	//������������� ���������� WinSock
	WSADATA data; //���������, ������� ���������� ���������� � ���������� ���������� Windows Sockets 
	int res = WSAStartup(0x0202, // ����� ������� ������ ���������� WinSock, ������� ��������� ������������
		&data); //��������� �� ��������� WSADATA
	if (res != 0) {
		cerr << "������ �������������: " << res;
		cin.get();
		return 0;
	}
	//int res = WSACleanup();
	//�������� ������
	SOCKET serverSocket = socket(AF_INET, //��������� �������, ������������ ���������� (IPv4)
		SOCK_STREAM, //��� ������������ ������ (������, ��������������� �� ����������)
		IPPROTO_TCP); //����� ������������ ��� �������� ������ ��������

	if (serverSocket == INVALID_SOCKET) {
		cerr << "������ �������� ������" << WSAGetLastError() << endl;
		cin.get();
		return 0;
	}

	//������������� ��������� sockaddr_in
	sockaddr_in sa;
	sa.sin_family = AF_INET; //��������� �������
	sa.sin_addr.S_un.S_addr = htonl(INADDR_ANY); //IP-����� ����������, � �������� ����� ����������� �������� �����������
	sa.sin_port = htons(SERVER_PORT); //�������������� ����

	//��������� ����� ������, �������� ���������� � ������ �����
	if (bind(serverSocket, //����������� �����, ������������ �������� socket
		(SOCKADDR*)&sa, // ���������, �������� ��������� ������� � ��������������� �������� ���������� (����� ����� � �������� � ������������� ����������)
		sizeof(sa)) //������ ���������
		== SOCKET_ERROR) {
		cerr << "������ ��������� ����� " << WSAGetLastError() << endl;
		cin.get();
		return 0;
	}

	//������������� ���������� ������
	if (listen(serverSocket, //����� �������
		2) //������������ ������ ������� ��������� �����������. 
		== SOCKET_ERROR) {
		cerr << "������ ������������� ������ " << WSAGetLastError() << endl;
		cin.get();
		return 0;
	}

	int sockAddrLen = sizeof(sockaddr_in); //��� accept
	sockaddr_in saClient;
	cout << "�������� ����������� ..." << endl;

	//�������� ��������
	SOCKET FirstClientSocket = accept(serverSocket, //��������� ��������������� �����
		(SOCKADDR*)&saClient, //����� ������������ �� ������� ��������� ����������� ������
		&sockAddrLen); //����� ����������, � ������� ���������� ����� ��������� 
	if (FirstClientSocket == INVALID_SOCKET) {
		cerr << "������ ���������� " << WSAGetLastError() << endl;
		cin.get();
		return 0;
	}
	else 
		cout << "����������� ������� ������ �������" << endl;
	SOCKET SecondClientSocket = accept(serverSocket, (SOCKADDR*)&saClient, &sockAddrLen);
	if (SecondClientSocket == INVALID_SOCKET) {
		cerr << "������ ���������� " << WSAGetLastError() << endl;
		cin.get();
		return 0;
	}
	else 
		cout << "����������� ������� ������ �������" << endl;

	char buff = '1';
	if (send(FirstClientSocket, &buff, sizeof(buff), 0) == SOCKET_ERROR) {
		cerr << "������ �������� ������ " << WSAGetLastError() << endl;
		cin.get();
		return 0;
	}
	buff = '2';
	if (send(SecondClientSocket, &buff, sizeof(buff), 0) == SOCKET_ERROR) {
		cerr << "������ �������� ������ " << WSAGetLastError() << endl;
		cin.get();
		return 0;
	}

	char error = '9';
	char point[3];
	cout << field;
	int i = 0;
	while (true) {
		if (turns < 9) {
			if (send(FirstClientSocket, field, sizeof(field), 0) == SOCKET_ERROR) {
				cerr << "������ �������� ������ " << WSAGetLastError() << endl;
				cin.get();
				return 0;
			}
			if (send(SecondClientSocket, field, sizeof(field), 0) == SOCKET_ERROR) {
				cerr << "������ �������� ������ " << WSAGetLastError() << endl;
				cin.get();
				return 0;
			}

			if (recv(FirstClientSocket, point, sizeof(point), 0) == SOCKET_ERROR) {
				cerr <<  "������ ������ ������ " << WSAGetLastError() << endl;
				cin.get();
				return 0;
			}
			int errorCode = redrawField(atoi(point), CLIENT);
			if (errorCode == 8) {
				field[33] = '8';
				if (send(FirstClientSocket, field, sizeof(field), 0) == SOCKET_ERROR) {
					cerr << "������ �������� ������ " << WSAGetLastError() << endl;
					cin.get();
					return 0;
				}
				if (send(SecondClientSocket, field, sizeof(field), 0) == SOCKET_ERROR) {
					cerr << "������ �������� ������ " << WSAGetLastError() << endl;
					cin.get();
					return 0;
				}
				return 0;
			}
			while (errorCode == 9) {
				if (send(FirstClientSocket, &error, sizeof(error), 0) == SOCKET_ERROR) {
					cerr << "������ �������� ������ " << WSAGetLastError() << endl;
					cin.get();
					return 0;
				}
				if (recv(FirstClientSocket, point, sizeof(point), 0) == SOCKET_ERROR) {
					cerr <<  "������ ������ ������ " << WSAGetLastError() << endl;
					cin.get();
					return 0;
				}
				errorCode = redrawField(atoi(point), CLIENT);
			}
			cout << field;
			if (turns > 4 && isFinish()) {
				if (atoi(finishMessage) == 5) {
					field[33] = '5';
					if (send(FirstClientSocket, field, sizeof(field), 0) == SOCKET_ERROR) {
						cerr << "������ �������� ������ " << WSAGetLastError() << endl;
						cin.get();
						return 0;
					}
					field[33] = '4';
					if (send(SecondClientSocket, field, sizeof(field), 0) == SOCKET_ERROR) {
						cerr << "������ �������� ������ " << WSAGetLastError() << endl;
						cin.get();
						return 0;
					}
					break;
				}
			}
			if (turns > 4 && isFinish()) {
				if (atoi(finishMessage) == 4) {
					field[33] = '4';
					if (send(FirstClientSocket, field, sizeof(field), 0) == SOCKET_ERROR) {
						cerr << "������ �������� ������ " << WSAGetLastError() << endl;
						cin.get();
						return 0;
					}
					field[33] = '5';
					if (send(SecondClientSocket, field, sizeof(field), 0) == SOCKET_ERROR) {
						cerr << "������ �������� ������ " << WSAGetLastError() << endl;
						cin.get();
						return 0;
					}
					break;
				}
			}

			if (send(FirstClientSocket, field, sizeof(field), 0) == SOCKET_ERROR) {
				cerr << "������ �������� ������ " << WSAGetLastError() << endl;
				cin.get();
				return 0;
			}
			if (send(SecondClientSocket, field, sizeof(field), 0) == SOCKET_ERROR) {
				cerr << "������ �������� ������ " << WSAGetLastError() << endl;
				cin.get();
				return 0;
			}

			if (recv(SecondClientSocket, point, sizeof(point), 0) == SOCKET_ERROR) {
				cerr <<  "������ ������ ������ " << WSAGetLastError() << endl;
				cin.get();
				return 0;
			}
			errorCode = redrawField(atoi(point), SERVER);
			if (errorCode == 8) {
				field[33] = '8';
				if (send(FirstClientSocket, field, sizeof(field), 0) == SOCKET_ERROR) {
					cerr << "������ �������� ������ " << WSAGetLastError() << endl;
					cin.get();
					return 0;
				}
				if (send(SecondClientSocket, field, sizeof(field), 0) == SOCKET_ERROR) {
					cerr << "������ �������� ������ " << WSAGetLastError() << endl;
					cin.get();
					return 0;
				}
				return 0;
			}
			while (errorCode == 9) {
				if (send(SecondClientSocket, &error, sizeof(error), 0) == SOCKET_ERROR) {
					cerr << "������ �������� ������ " << WSAGetLastError() << endl;
					cin.get();
					return 0;
				}
				if (recv(SecondClientSocket, point, sizeof(point), 0) == SOCKET_ERROR) {
					cerr <<  "������ ������ ������ " << WSAGetLastError() << endl;
					cin.get();
					return 0;
				}
				errorCode = redrawField(atoi(point), SERVER);
			}

			cout << field;
			if (turns > 4 && isFinish()) {
				if (atoi(finishMessage) == 5) {
					field[33] = '5';
					if (send(FirstClientSocket, field, sizeof(field), 0) == SOCKET_ERROR) {
						cerr << "������ �������� ������ " << WSAGetLastError() << endl;
						cin.get();
						return 0;
					}
					field[33] = '4';
					if (send(SecondClientSocket, field, sizeof(field), 0) == SOCKET_ERROR) {
						cerr << "������ �������� ������ " << WSAGetLastError() << endl;
						cin.get();
						return 0;
					}
					break;
				}
			}
			if (turns > 4 && isFinish()) {
				if (atoi(finishMessage) == 4) {
					field[33] = '4';
					if (send(FirstClientSocket, field, sizeof(field), 0) == SOCKET_ERROR) {
						cerr << "������ �������� ������ " << WSAGetLastError() << endl;
						cin.get();
						return 0;
					}
					field[33] = '5';
					if (send(SecondClientSocket, field, sizeof(field), 0) == SOCKET_ERROR) {
						cerr << "������ �������� ������ " << WSAGetLastError() << endl;
						cin.get();
						return 0;
					}
					break;
				}
			}
		}	
	}

	//�������� ������
	closesocket(serverSocket);

	system("pause");
	return 0;
}