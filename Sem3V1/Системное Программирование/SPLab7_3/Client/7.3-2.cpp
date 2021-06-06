#include <iostream>
#include <Windows.h>
#pragma comment(lib, "WS2_32.lib")
#define SERVER_PORT 3000
#define UDP_SERVER_PORT 3001
using namespace std;

int errorFunc()
{
	cout << "Ошибка" << WSAGetLastError();
	system("pause");
	return 0;
}

bool first = false;

char poleInString[] = { '-' ,'-','-', '\n',
						'-','-','-', '\n',
						'-','-' ,'-','\n', '\0' };

bool draw()
{
	if (poleInString[0] != '-' && poleInString[1] != '-' && poleInString[2] != '-' &&
		poleInString[4] != '-' &&poleInString[5] != '-' &&poleInString[6] != '-' &&
		poleInString[8] != '-' &&poleInString[9] != '-' &&poleInString[10] != '-') return true;
	else return false;
}

bool move(int hod, int who)
{
	switch (hod)
	{
	case(11):
	{
		if (poleInString[0] == '-')
		{
			if (who == 1) poleInString[0] = 'X';
			else poleInString[0] = 'O';
			return true;
		}
		else return false;
		break;
	}
	case(21):
	{
		if (poleInString[1] == '-')
		{
			if (who == 1) poleInString[1] = 'X';
			else poleInString[1] = 'O';
			return true;
		}
		else return false;
		break;
	}
	case(31):
	{
		if (poleInString[2] == '-')
		{
			if (who == 1) poleInString[2] = 'X';
			else poleInString[2] = 'O';
			return true;
		}
		else return false;
		break;
	}
	case(12):
	{
		if (poleInString[4] == '-')
		{
			if (who == 1) poleInString[4] = 'X';
			else poleInString[4] = 'O';
			return true;
		}
		else return false;
		break;
	}
	case(22):
	{
		if (poleInString[5] == '-')
		{
			if (who == 1) poleInString[5] = 'X';
			else poleInString[5] = 'O';
			return true;
		}
		else return false;
		break;
	}
	case(32):
	{
		if (poleInString[6] == '-')
		{
			if (who == 1) poleInString[6] = 'X';
			else poleInString[6] = 'O';
			return true;
		}
		else return false;
		break;
	}
	case(13):
	{
		if (poleInString[8] == '-')
		{
			if (who == 1) poleInString[8] = 'X';

			else poleInString[8] = 'O';
			return true;
		}
		else return false;
		break;
	}
	case(23):
	{
		if (poleInString[9] == '-')
		{
			if (who == 1) poleInString[9] = 'X';
			else poleInString[9] = 'O';
			return true;
		}
		else return false;
		break;
	}
	case(33):
	{
		if (poleInString[10] == '-')
		{
			if (who == 1) poleInString[10] = 'X';
			else poleInString[10] = 'O';
			return true;
		}
		else return false;
		break;
	}
	default:
		return false;
	}
}

bool win(int n)
{
	if (n == 1)
	{
		if (poleInString[0] == 'X' && poleInString[1] == 'X' && poleInString[2] == 'X') return true;
		if (poleInString[2] == 'X' && poleInString[6] == 'X' && poleInString[10] == 'X') return true;
		if (poleInString[8] == 'X' && poleInString[9] == 'X' && poleInString[10] == 'X') return true;
		if (poleInString[0] == 'X' && poleInString[4] == 'X' && poleInString[8] == 'X') return true;
		if (poleInString[0] == 'X' && poleInString[5] == 'X' && poleInString[10] == 'X') return true;
		if (poleInString[2] == 'X' && poleInString[5] == 'X' && poleInString[8] == 'X') return true;
		if (poleInString[4] == 'X' && poleInString[5] == 'X' && poleInString[6] == 'X') return true;
		if (poleInString[1] == 'X' && poleInString[5] == 'X' && poleInString[9] == 'X') return true;
	}
	else {
		if (poleInString[0] == 'O' && poleInString[1] == 'O' && poleInString[2] == 'O') return true;
		if (poleInString[2] == 'O' && poleInString[6] == 'O' && poleInString[10] == 'O') return true;
		if (poleInString[8] == 'O' && poleInString[9] == 'O' && poleInString[10] == 'O') return true;
		if (poleInString[0] == 'O' && poleInString[4] == 'O' && poleInString[8] == 'O') return true;
		if (poleInString[0] == 'O' && poleInString[5] == 'O' && poleInString[10] == 'O') return true;
		if (poleInString[2] == 'O' && poleInString[5] == 'O' && poleInString[8] == 'O') return true;
		if (poleInString[4] == 'O' && poleInString[5] == 'O' && poleInString[6] == 'O') return true;
		if (poleInString[1] == 'O' && poleInString[5] == 'O' && poleInString[9] == 'O') return true;
	}
	return false;
}



int main()
{
	setlocale(0, "");
	WSADATA wsadata;
	int res = WSAStartup(MAKEWORD(2, 2), &wsadata);

	int sockAddrLen = sizeof(sockaddr_in);

	SOCKET serverUdpSocket = socket(AF_INET, 
		SOCK_DGRAM, // сокеты без установления соединений - дейтаграммные
		IPPROTO_UDP);
	if (serverUdpSocket == INVALID_SOCKET) return errorFunc();

	sockaddr_in UDP_SI;
	UDP_SI.sin_family = AF_INET;
	UDP_SI.sin_addr.S_un.S_addr = htonl(INADDR_ANY); // принимать все адресса
	UDP_SI.sin_port = htons(UDP_SERVER_PORT);
	if (bind(serverUdpSocket, (SOCKADDR*)&UDP_SI, sizeof(UDP_SI)) == SOCKET_ERROR) return errorFunc();

	SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (server == INVALID_SOCKET) return errorFunc();

	sockaddr_in sa;
	sa.sin_family = AF_INET;
	sa.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	sa.sin_port = htons(SERVER_PORT);
	if (bind(server, (SOCKADDR*)&sa, sizeof(sa)) == SOCKET_ERROR) return errorFunc();

	if (listen(server, 2) == SOCKET_ERROR) return errorFunc();
	char b1;
	sockaddr_in sAddr;
	if (recvfrom(serverUdpSocket, &b1, 2, 0, (SOCKADDR*)&sAddr, &sockAddrLen) == SOCKET_ERROR) return errorFunc();
	if (sendto(serverUdpSocket, " ", 2, 0, (SOCKADDR*)&sAddr, sockAddrLen) == SOCKET_ERROR) return errorFunc();

	sockaddr_in saClient;
	cout << "Ожидание клиентов" << endl;
	SOCKET FirstClientSocket = accept(server, (SOCKADDR*)&saClient, &sockAddrLen);
	if (FirstClientSocket == INVALID_SOCKET) return errorFunc();
	else cout << "Клиент подключен" << endl;

	if (recvfrom(serverUdpSocket, &b1, 2, 0, (SOCKADDR*)&sAddr, &sockAddrLen) == SOCKET_ERROR) return errorFunc();
	if (sendto(serverUdpSocket, " ", 2, 0, (SOCKADDR*)&sAddr, sockAddrLen) == SOCKET_ERROR) return errorFunc();

	closesocket(serverUdpSocket);
	SOCKET SecondClientSocket = accept(server, (SOCKADDR*)&saClient, &sockAddrLen);
	if (SecondClientSocket == INVALID_SOCKET) return errorFunc();
	else cout << "Клиент подключен" << endl;

	char x = '1';
	char xx = '2';
	if (send(FirstClientSocket, &x, 1, 0) == SOCKET_ERROR) {
		cerr << "Сообщение не отправлено. Ошибка: " << WSAGetLastError() << endl;
		cin.get();
		return 0;
	}
	if (send(SecondClientSocket, &xx, 1, 0) == SOCKET_ERROR) {
		cerr << "Сообщение не отправлено. Ошибка: " << WSAGetLastError() << endl;
		cin.get();
		return 0;
	}


	int n = 0;
	char hod[256];
	char bad = 'b';
	char good = 'g';
	char b = '0';
	int Ihod = 0;
	char buff = '1';
	while (true)
	{


		cout << "проход" << n++ << endl;

		if (recv(FirstClientSocket, hod, sizeof(hod), NULL) == SOCKET_ERROR)
		{
			cerr << "1 " << endl;
			system("pause");
		};

		Ihod = atoi(hod);
		//		cout << Ihod << endl;
		if (Ihod != 0) {
			if (!move(Ihod, 1))
			{
				while (move(Ihod, 1) == false)
				{
					if (send(FirstClientSocket, &bad, sizeof(bad), 0) == SOCKET_ERROR) {
						cerr << "2 " << endl;
						system("pause");
					};
					if (recv(FirstClientSocket, hod, sizeof(hod), NULL) == SOCKET_ERROR)
					{
						cerr << "1 " << endl;
						system("pause");
					};
					Ihod = atoi(hod);
				}
				if (send(FirstClientSocket, &good, sizeof(good), 0) == SOCKET_ERROR) {
					cerr << "2 " << endl;
					system("pause");
				};
			}
			else if (send(FirstClientSocket, &good, sizeof(good), 0) == SOCKET_ERROR) {
				cerr << "2 " << endl;
				system("pause");
			};

			if (send(FirstClientSocket, poleInString, sizeof(poleInString), 0) == SOCKET_ERROR) {
				cerr << "2 " << endl;
				system("pause");
			};

			if (win(1)) b = '1';
			if (draw()) b = '3';
			if (send(FirstClientSocket, &b, 1, 0) == SOCKET_ERROR) {
				cerr << "2 " << endl;
				system("pause");
			};
			if (send(SecondClientSocket, poleInString, sizeof(poleInString), 0) == SOCKET_ERROR) { cerr << "3 " << endl; system("pause"); };
			if (send(SecondClientSocket, &b, 1, 0) == SOCKET_ERROR) {
				cerr << "2 " << endl;
				system("pause");
			};
		}
		if (recv(SecondClientSocket, hod, sizeof(hod), NULL) == SOCKET_ERROR) { cerr << "4 " << endl; system("pause"); };
		Ihod = atoi(hod);
		if (Ihod != 0) {
			if (!move(Ihod, 2))
			{
				while (move(Ihod, 2) == false)
				{
					if (send(SecondClientSocket, &bad, sizeof(bad), 0) == SOCKET_ERROR) {
						cerr << "2 " << endl;
						system("pause");
					};
					if (recv(SecondClientSocket, hod, sizeof(hod), NULL) == SOCKET_ERROR)
					{
						cerr << "1 " << endl;
						system("pause");
					};
					Ihod = atoi(hod);
				}
				if (send(SecondClientSocket, &good, sizeof(good), 0) == SOCKET_ERROR) {
					cerr << "2 " << endl;
					system("pause");
				};
			}
			else if (send(SecondClientSocket, &good, sizeof(good), 0) == SOCKET_ERROR) {
				cerr << "2 " << endl;
				system("pause");
			};
			if (send(SecondClientSocket, poleInString, sizeof(poleInString), 0) == SOCKET_ERROR) { cerr << "3 " << endl; system("pause"); };
			if (win(2)) b = '2';
			if (draw()) b = '3';
			if (send(SecondClientSocket, &b, 1, 0) == SOCKET_ERROR) { cerr << "3 " << endl; system("pause"); };
			if (send(FirstClientSocket, poleInString, sizeof(poleInString), 0) == SOCKET_ERROR) {
				cerr << "2 " << endl;
				system("pause");
			};
			if (send(FirstClientSocket, &b, 1, 0) == SOCKET_ERROR) { cerr << "3 " << endl; system("pause"); };
		}


	}

	system("pause");
	return 0;
}