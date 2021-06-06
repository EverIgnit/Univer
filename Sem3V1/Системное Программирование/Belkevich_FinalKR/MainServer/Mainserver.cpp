#include <windows.h>
#include <iostream>
#pragma comment(lib, "WS2_32.lib")

using namespace std;

#define SERVER_PORT 23123
#define CLIENT 0
#define SERVER 1


//	!	!	!	!	!	!	!	!	!	!	!	!	!	!	!
// Для подключения большего числа клиентов изменить этот параметр
unsigned short n = 10;
//	!	!	!	!	!	!	!	!	!	!	!	!	!	!	!
char computerName[80];
char pipeName[80];
HANDLE hNamedPipe;
DWORD dwBytesRead;
char buff[256];
int sockAddrLen = sizeof(sockaddr_in); //для accept
sockaddr_in saClient;
SOCKET serverSocket;
SOCKET* Clients = new SOCKET[n];

DWORD WINAPI AddClient(LPVOID param) {
	//создание клиентов
	int count;
	for (count = 0; count < n; count++) {
		Clients[count] = accept(serverSocket, //серверный «прослушиваемый» сокет
			(SOCKADDR*)&saClient, //адрес извлеченного из очереди ожидающих подключений сокета
			&sockAddrLen); //адрес переменной, в которую помещается длина структуры 
		if (Clients[count] == INVALID_SOCKET) {
			cerr << "Ошибка извлечения " << WSAGetLastError() << endl;
			cin.get();
			return ;
		}
		else
			cout << "Подключение клиента прошло успешно" << endl;
	}
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	cout << "Enter Servername: ";
	cin.getline(computerName, 80);

	wsprintf(pipeName, "\\\\%s\\pipe\\MyPipe", computerName);  //преобразуем введённое имя канала в нужный формат

	if (!WaitNamedPipe(pipeName,     //когда канал pipeName будет доступен для соединения
		NMPWAIT_WAIT_FOREVER)) {
		cout << "The pipe doesn't exist or is already taken" << endl
			<< "Error: " << GetLastError() << endl;
		cin.get();
		return 0;
	}

	hNamedPipe = CreateFile(pipeName, GENERIC_READ, 0, NULL,/*security attributes*/OPEN_EXISTING, 0, /*attribute file*/NULL/*наследование*/);  //подключение к каналу

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

	//инициальзация библиотеки WinSock
	WSADATA data; //структура, которая возвращает информацию о настройках библиотеки Windows Sockets 
	int res = WSAStartup(0x0202, /*задаёт старшую версию библиотеки WinSock, которую требуется использовать */&data);
	if (res != 0) {
		cerr << "Ошибка инициализации: " << res;
		cin.get();
		return 0;
	}
	//создание сокета
	serverSocket = socket(AF_INET, /*IPv4*/SOCK_STREAM, /*cокеты, ориентированные на соединение*/IPPROTO_TCP/*TCP*/);

	if (serverSocket == INVALID_SOCKET) {
		cerr << "Ошибка создания сокета" << WSAGetLastError() << endl;
		cin.get();
		return 0;
	}

	//инициализация структуры sockaddr_in
	sockaddr_in sa;
	sa.sin_family = AF_INET; // IPv4
	sa.sin_addr.S_un.S_addr = htonl(INADDR_ANY); //IP интерфейса, с которого будут приниматься входящие подключения
	sa.sin_port = htons(SERVER_PORT); // порт

	// установка связи сокета, сетевого интерфейса и номера порта
	if (bind(serverSocket, /*несвязанный сокет*/(SOCKADDR*)&sa, /* задаёт семейство адресов, номер порта и привязку к интерфейсу)*/sizeof(sa))== SOCKET_ERROR) {
		cerr << "Ошибка установки связи " << WSAGetLastError() << endl;
		cin.get();
		return 0;
	}

	//прослушивание серверного сокета
	if (listen(serverSocket, /*сокет сервера*/n) /*максимальный размер очереди ожидающих подключений*/== SOCKET_ERROR) {
		cerr << "Ошибка прослушивания сокета " << WSAGetLastError() << endl;
		cin.get();
		return 0;
	}

	
	cout << "Ожидание подключения ..." << endl;

	LPDWORD idT = 0;
	HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)AddClient, 0, 0, idT);
	if (!hThread) {
		cout << "error\n";
		system("pause");
		return 0;
	}

	while (buff != "Exit") {

		if (!ReadFile(hNamedPipe, buff, sizeof(buff), &dwBytesRead, NULL)) {  //чтение сообщения
			cerr << "Failed to read the message" << endl << "Error: " << GetLastError() << endl;
			CloseHandle(hNamedPipe);
			cin.get();
			system("pause");
			return 0;
		}

		for (int i = 0; i < n; i++) {
			if (send(Clients[i], buff, sizeof(buff), 0) == SOCKET_ERROR) {
				cerr << "Ошибка передачи данных " << WSAGetLastError() << endl;
				return 0;
			}
		}
	}

	//закрытие сокета и канала
	DisconnectNamedPipe(hNamedPipe);
	CloseHandle(hNamedPipe);
	closesocket(serverSocket);
	WSACleanup();
	delete[]Clients;

	system("pause");
	return 0;
}
