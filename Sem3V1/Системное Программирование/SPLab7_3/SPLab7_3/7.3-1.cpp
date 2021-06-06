#include <iostream>
#include <Windows.h>
#pragma comment(lib, "WS2_32.lib")
#define SERVER_PORT 3000
#define UDP_SERVER_PORT 3001
using namespace std;
char buff;
char point[256];

bool first = false;
int errorFunc()
{
	cout << "Error" << GetLastError() << endl;
	system("pause");
	return 0;
}
int main()
{
	setlocale(0, "");
	WSADATA wsadata;
	int res = WSAStartup(MAKEWORD(2, 2), &wsadata);

	char ca[2];
	SOCKET serverUdpSocket = socket(AF_INET,
		SOCK_DGRAM, 
		IPPROTO_UDP);
	if (serverUdpSocket == INVALID_SOCKET) return errorFunc();
// установление режима в широковещателе
	int one = 1;
	if (setsockopt(serverUdpSocket, SOL_SOCKET, SO_BROADCAST, (char*)&one, sizeof(one)) < 0) return errorFunc();

	sockaddr_in UDP_SI;
	UDP_SI.sin_family = AF_INET;
	//UDP_SI.sin_addr.S_un.S_addr = htonl(INADDR_BROADCAST);  
	UDP_SI.sin_addr.S_un.S_addr = inet_addr("255.255.255.255"); // широковещательный адрес
	UDP_SI.sin_port = htons(UDP_SERVER_PORT);

	if (sendto(serverUdpSocket, " ", 2, 0, (SOCKADDR*)&UDP_SI, sizeof(UDP_SI)) == SOCKET_ERROR) return errorFunc();
	int a = sizeof(UDP_SI);
	if (recvfrom(serverUdpSocket, ca, sizeof(ca), 0, (SOCKADDR*)&UDP_SI, &a) == SOCKET_ERROR) return errorFunc();

	SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (client == INVALID_SOCKET) return errorFunc();
	closesocket(serverUdpSocket);
	sockaddr_in sa;
	ZeroMemory(&sa, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_addr.S_un.S_addr = UDP_SI.sin_addr.S_un.S_addr;
	sa.sin_port = htons(SERVER_PORT);

	int connection_status = connect(client, (SOCKADDR*)&sa, sizeof(sa));
	if (connection_status == SOCKET_ERROR) return errorFunc();
	else cout << "Соединение установлено" << endl;


	char mes;
	if (recv(client, &mes, 1, 0) == SOCKET_ERROR) {
		cerr << "Связывание не произошло. Ошибка: " << WSAGetLastError() << endl;
		cin.get();
		return 0;
	}
	cout << "Ходы: \n 11-21-31 \n 12-22-32 \n 13-23-33 \n";
	if (mes == '1') {
		first = true;
		cout << "Ты ходишь первый" << endl;
	}
	else if (mes == '2')
	{
		cout << "Ты ходишь второй" << endl;
	}
	char mes1[13];
	char b;
	int n = 0;
	int Ihod = 0;
	if (first)
	{
		while (true)
		{
			cout << "Ваш ход. " << endl;
			cin.getline(point, sizeof(point));

			if (send(client, point, sizeof(point), 0) == SOCKET_ERROR) {
				cerr << "Сообщение не отправлено. Ошибка: " << WSAGetLastError() << endl;
				cin.get();
				return 0;
			}

			if (recv(client, &b, sizeof(b), 0) == SOCKET_ERROR) {
				cerr << "Приём не выполнен. Ошибка: " << WSAGetLastError() << endl;
				cin.get();
				return 0;
			}
			if (b != 'g')
			{
				while (b != 'g')
				{
					cout << "Неправильный ход" << endl;
					cin.getline(point, sizeof(point));
					if (send(client, point, sizeof(point), 0) == SOCKET_ERROR) {
						cerr << "Сообщение не отправлено. Ошибка: " << WSAGetLastError() << endl;
						cin.get();
						return 0;
					}

					if (recv(client, &b, sizeof(b), 0) == SOCKET_ERROR) {
						cerr << "Приём не выполнен. Ошибка: " << WSAGetLastError() << endl;
						cin.get();
						return 0;
					}
				}
			}


			cout << endl;
			if (recv(client, mes1, sizeof(mes1), 0) == SOCKET_ERROR) {
				cerr << "Приём не выполнен. Ошибка: " << WSAGetLastError() << endl;
				cin.get();
				return 0;
			}
			cout << mes1 << endl;


			if (recv(client, &b, sizeof(mes1), 0) == SOCKET_ERROR) {
				cerr << "Приём не выполнен. Ошибка: " << WSAGetLastError() << endl;
				cin.get();
				return 0;
			}
			if (b == '1') {
				cout << "Вы победили." << endl;
				system("pause");
				break;
			}
			if (b == '2') {
				cout << "Вы проиграли." << endl;
				system("pause");
				break;
			}
			if (b == '3')
			{
				cout << "Ничья." << endl;
				system("pause");
				break;
			}

			cout << "Ход противника. " << endl;
			if (recv(client, mes1, sizeof(mes1), 0) == SOCKET_ERROR) {
				cerr << "Приём не выполнен. Ошибка: " << WSAGetLastError() << endl;
				cin.get();
				return 0;
			}
			cout << mes1 << endl;


			if (recv(client, &b, sizeof(mes1), 0) == SOCKET_ERROR) {
				cerr << "Приём не выполнен. Ошибка: " << WSAGetLastError() << endl;
				cin.get();
				return 0;
			}
			if (b == '1') {
				cout << "Вы победили." << endl;
				system("pause");
				break;
			}
			if (b == '2') {
				cout << "Вы проиграли." << endl;
				system("pause");
				break;
			}
			if (b == '3')
			{
				cout << "Ничья." << endl;
				system("pause");
				break;
			}

		}

	}

	else
	{
		while (true)
		{
			cout << "Ход противника. " << endl;

			if (recv(client, mes1, sizeof(mes1), 0) == SOCKET_ERROR) {
				cerr << "Приём не выполнен. Ошибка: " << WSAGetLastError() << endl;
				cin.get();
				return 0;
			}
			cout << mes1 << endl;

			if (recv(client, &b, sizeof(mes1), 0) == SOCKET_ERROR) {
				cerr << "Приём не выполнен. Ошибка: " << WSAGetLastError() << endl;
				cin.get();
				return 0;
			}
			if (b == '2') {
				cout << "Вы победили." << endl;
				system("pause");
				break;
			}
			if (b == '1') {
				cout << "Вы проиграли." << endl;
				system("pause");
				break;
			}
			if (b == '3')
			{
				cout << "Ничья" << endl;
				system("pause");
				break;
			}


			cout << "Ваш ход. " << endl;

			cin.getline(point, sizeof(point));

			Ihod = atoi(point);

			if (send(client, point, sizeof(point), 0) == SOCKET_ERROR) {
				cerr << "Сообщение не отправлено. Ошибка: " << WSAGetLastError() << endl;
				cin.get();
				return 0;
			}

			if (recv(client, &b, sizeof(b), 0) == SOCKET_ERROR) {
				cerr << "Приём не выполнен. Ошибка: " << WSAGetLastError() << endl;
				cin.get();
				return 0;
			}
			if (b != 'g')
			{
				while (b != 'g')
				{
					cout << "Неправильный ход" << endl;
					cin.getline(point, sizeof(point));
					if (send(client, point, sizeof(point), 0) == SOCKET_ERROR) {
						cerr << "Сообщение не отправлено. Ошибка: " << WSAGetLastError() << endl;
						cin.get();
						return 0;
					}

					if (recv(client, &b, sizeof(b), 0) == SOCKET_ERROR) {
						cerr << "Приём не выполнен. Ошибка: " << WSAGetLastError() << endl;
						cin.get();
						return 0;
					}
				}
			}






			if (recv(client, mes1, sizeof(mes1), 0) == SOCKET_ERROR) {
				cerr << "Приём не выполнен. Ошибка: " << WSAGetLastError() << endl;
				cin.get();
				return 0;
			}

			cout << mes1 << endl;
			if (recv(client, &b, sizeof(mes1), 0) == SOCKET_ERROR) {
				cerr << "Приём не выполнен. Ошибка: " << WSAGetLastError() << endl;
				cin.get();
				return 0;
			}
			if (b == '2') {
				cout << "Вы победили." << endl;
				system("pause");
				break;
			}
			if (b == '1') {
				cout << "Вы проиграли." << endl;
				system("pause");
				break;
			}
			if (b == '3')
			{
				cout << "Ничья." << endl;
				system("pause");
				break;
			}
		}
	}


	WSACleanup();
	system("pause");
	return 0;
}