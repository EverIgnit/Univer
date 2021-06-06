#include <windows.h>
#include <iostream>
#pragma comment(lib, "WS2_32.lib")
using namespace std;
#define SERVER_PORT 23123
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	cout << "Введите IP сервера: ";
	char addr[20];
	cin.getline(addr, sizeof(addr));

	WSADATA data;
	int res = WSAStartup(MAKEWORD(2, 2), &data);
	SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (clientSocket == INVALID_SOCKET) {
		cout << "Ошибка создания сокета." << WSAGetLastError() << endl;
		cin.get();
		return 0;
	}
	sockaddr_in sa;
	ZeroMemory(&sa, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_addr.S_un.S_addr = inet_addr(addr);
	sa.sin_port = htons(SERVER_PORT);

	if (connect(clientSocket, (SOCKADDR*)&sa, sizeof(sa)) == SOCKET_ERROR) {
		cerr << "Ошибка подключения" << WSAGetLastError() << endl;
		cin.get();
		return 0;
	}
	else 
		cout << "Соединение установлено..." << endl;

	char buff[256];
	while (buff != "Exit") {
		if (recv(clientSocket, buff, sizeof(buff), 0) == SOCKET_ERROR) {
			cerr << "Ошибка приема данных " << WSAGetLastError() << endl;
			cin.get();
			return 0;
		}
		cout << buff << endl;
	}

	system("pause");
	return 0;
}