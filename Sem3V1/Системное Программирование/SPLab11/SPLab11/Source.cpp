//sc create GOOD_SERVICE binPath= "C:\\Users\\1801080061\\Downloads\\SPLab11\\Debug\\SPLab11.exe"
#include <iostream>
#include <fstream>
#include <Windows.h>
#pragma comment(lib, "WS2_32.lib")
#define SERVER_PORT 3000
#define UDP_SERVER_PORT 3001
using namespace std;

_SERVICE_STATUS serviceStatus;
SERVICE_STATUS_HANDLE ServiceController;
SOCKET server;
ofstream fout("D:\\ServiceLog.txt");
char service_name[] = "GOOD_SERVICE";
void errorFunc(const char* n)
{
	fout << "Error " << n << " " << WSAGetLastError() << endl;
	fout.close();
	closesocket(server);
	serviceStatus.dwCheckPoint++;
	serviceStatus.dwCurrentState = SERVICE_STOPPED;
	SetServiceStatus(ServiceController, &serviceStatus);
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
void newPole() {
	poleInString[0] = '-';
	poleInString[1] = '-';
	poleInString[2] = '-';
	poleInString[4] = '-';
	poleInString[5] = '-';
	poleInString[6] = '-';
	poleInString[8] = '-';
	poleInString[9] = '-';
	poleInString[10] = '-';
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


VOID WINAPI ServiceMain(DWORD dwARGC, LPTSTR *lpszArgv);
VOID WINAPI ServiceCtrlHandler(DWORD control, DWORD eventType, LPVOID eventData, LPVOID eventContext);


int main() {

	SERVICE_TABLE_ENTRY service_table[] = { { service_name, ServiceMain },{ NULL, NULL } };
	if (!StartServiceCtrlDispatcher(service_table)) {
		fout << "StartServiceCtrlDispatcher error" << WSAGetLastError() << endl;
		fout.close();
	}
	return 0;
}

VOID WINAPI ServiceMain(DWORD dwARGC, LPTSTR* argv) {

	ServiceController = RegisterServiceCtrlHandlerEx(service_name, (LPHANDLER_FUNCTION_EX)&ServiceCtrlHandler, NULL);
	if (ServiceController == 0) {
		fout << "RegisterServiceCtrlHandlerEx error" << WSAGetLastError() << endl;
		fout.close();
		closesocket(server);
		serviceStatus.dwCheckPoint++;
		serviceStatus.dwCurrentState = SERVICE_STOPPED;
		SetServiceStatus(ServiceController, &serviceStatus);
	}
	serviceStatus.dwServiceType = SERVICE_WIN32_OWN_PROCESS; // сервис как самостоятельный процесс со своими ресурсами;
	serviceStatus.dwCurrentState = SERVICE_START_PENDING; // сервер стартует
	serviceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP; // служба может быть остановлена
	serviceStatus.dwWin32ExitCode = NO_ERROR;
	serviceStatus.dwCheckPoint = 0;
	serviceStatus.dwServiceSpecificExitCode = 0; // код возникающий при возникновении ошибки
	serviceStatus.dwWaitHint = 5000;

	if (!SetServiceStatus(ServiceController, &serviceStatus)) {
		fout << "SetServiceStatus1 error" << WSAGetLastError() << endl;
		fout.close();
		closesocket(server);
	}

	int sockAddrLen;
	SOCKET serverUdpSocket;
	sockaddr_in UDP_SI; 
	sockaddr_in sa;
	sockaddr_in sAddr;
	char b1;
	sockaddr_in saClient;
	SOCKET FirstClientSocket;

	SOCKET SecondClientSocket;
	char x = '1';
	char xx = '2';
	bool asd = false;
	int n = 0;
	char hod[256];
	char bad = 'b';
	char good = 'g';
	char b = '0';
	int Ihod = 0;
	char buff = '1';
	int res;
	WSADATA wsadata;
	setlocale(0, "");
	while (true) {

		newPole();
		win(9);
		draw();
		asd = false;
		n = 0;

		bad = 'b';
		good = 'g';
		b = '0';
		Ihod = 0;
		buff = '1';
		res = WSAStartup(MAKEWORD(2, 2), &wsadata);
		sockAddrLen = sizeof(sockaddr_in);

		serverUdpSocket = socket(AF_INET,
			SOCK_DGRAM, // сокеты без установления соединений - дейтаграммные
			IPPROTO_UDP);
		if (serverUdpSocket == INVALID_SOCKET) errorFunc("ServerUDpSocket");

		UDP_SI;
		UDP_SI.sin_family = AF_INET;
		UDP_SI.sin_addr.S_un.S_addr = htonl(INADDR_ANY); // принимать все адресса
		UDP_SI.sin_port = htons(UDP_SERVER_PORT);
		if (bind(serverUdpSocket, (SOCKADDR*)&UDP_SI, sizeof(UDP_SI)) == SOCKET_ERROR) errorFunc("bind1");

		server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (server == INVALID_SOCKET) errorFunc("socket");

		sa;
		sa.sin_family = AF_INET;
		sa.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
		sa.sin_port = htons(SERVER_PORT);
		if (bind(server, (SOCKADDR*)&sa, sizeof(sa)) == SOCKET_ERROR) errorFunc("bind");

		if (listen(server, 2) == SOCKET_ERROR) errorFunc("listen");

		serviceStatus.dwCheckPoint++;
		serviceStatus.dwCurrentState = SERVICE_RUNNING;
		if (!SetServiceStatus(ServiceController, &serviceStatus)) {
			fout << "Sending message error" << WSAGetLastError() << endl;
			fout.close();
			closesocket(server);
		}

		sAddr;
		if (recvfrom(serverUdpSocket, &b1, 2, 0, (SOCKADDR*)&sAddr, &sockAddrLen) == SOCKET_ERROR) errorFunc("recvfrom");
		if (sendto(serverUdpSocket, " ", 2, 0, (SOCKADDR*)&sAddr, sockAddrLen) == SOCKET_ERROR) errorFunc("sendto");


		cout << "Ожидание клиентов" << endl;
		FirstClientSocket = accept(server, (SOCKADDR*)&saClient, &sockAddrLen);
		if (FirstClientSocket == INVALID_SOCKET) errorFunc("FCsocket");
		//else cout << "Клиент подключен" << endl;

		if (recvfrom(serverUdpSocket, &b1, 2, 0, (SOCKADDR*)&sAddr, &sockAddrLen) == SOCKET_ERROR) errorFunc("recvf");
		if (sendto(serverUdpSocket, " ", 2, 0, (SOCKADDR*)&sAddr, sockAddrLen) == SOCKET_ERROR) errorFunc("sendto");

		closesocket(serverUdpSocket);
		SecondClientSocket = accept(server, (SOCKADDR*)&saClient, &sockAddrLen);
		if (SecondClientSocket == INVALID_SOCKET) errorFunc("SCsocket");
		//else cout << "Клиент подключен" << endl;


		if (send(FirstClientSocket, &x, 1, 0) == SOCKET_ERROR) errorFunc("send");
		if (send(SecondClientSocket, &xx, 1, 0) == SOCKET_ERROR) errorFunc("send");


		while (true)
		{


			//cout << "проход" << n++ << endl;

			if (recv(FirstClientSocket, hod, sizeof(hod), NULL) == SOCKET_ERROR)
				errorFunc("recv1");

			Ihod = atoi(hod);
			//		cout << Ihod << endl;
			if (Ihod != 0) {
				if (!move(Ihod, 1))
				{
					while (move(Ihod, 1) == false)
					{
						if (send(FirstClientSocket, &bad, sizeof(bad), 0) == SOCKET_ERROR) errorFunc("send1");
						if (recv(FirstClientSocket, hod, sizeof(hod), NULL) == SOCKET_ERROR)
						{
							errorFunc("recv2");
						};
						Ihod = atoi(hod);
					}
					if (send(FirstClientSocket, &good, sizeof(good), 0) == SOCKET_ERROR) {
						errorFunc("send2");
					};
				}
				else if (send(FirstClientSocket, &good, sizeof(good), 0) == SOCKET_ERROR) {
					errorFunc("send3");
				};

				if (send(FirstClientSocket, poleInString, sizeof(poleInString), 0) == SOCKET_ERROR) {
					errorFunc("send4");
				};

				if (win(1)) {
					b = '1';
					asd = true;
				};
				if (draw()) {
					b = '3';
					asd = true;
				};
				if (send(FirstClientSocket, &b, 1, 0) == SOCKET_ERROR) {
					errorFunc("send5");
				};
				if (send(SecondClientSocket, poleInString, sizeof(poleInString), 0) == SOCKET_ERROR) { errorFunc("send6"); };
				if (send(SecondClientSocket, &b, 1, 0) == SOCKET_ERROR) {
					errorFunc("send7");
				};
				if (asd == true) break;
			}
			if (recv(SecondClientSocket, hod, sizeof(hod), NULL) == SOCKET_ERROR) { errorFunc("recv3"); };
			Ihod = atoi(hod);
			if (Ihod != 0) {
				if (!move(Ihod, 2))
				{
					while (move(Ihod, 2) == false)
					{
						if (send(SecondClientSocket, &bad, sizeof(bad), 0) == SOCKET_ERROR) {
							errorFunc("send8");
						};
						if (recv(SecondClientSocket, hod, sizeof(hod), NULL) == SOCKET_ERROR)
						{
							errorFunc("recv4");
						};
						Ihod = atoi(hod);
					}
					if (send(SecondClientSocket, &good, sizeof(good), 0) == SOCKET_ERROR) {
						errorFunc("send9");
					};
				}
				else if (send(SecondClientSocket, &good, sizeof(good), 0) == SOCKET_ERROR) {
					errorFunc("send10");
				};
				if (send(SecondClientSocket, poleInString, sizeof(poleInString), 0) == SOCKET_ERROR) { errorFunc("send11"); };
				if (win(2)) {
					b = '2';
					asd = true;
				};
				if (draw()) {
					b = '3';
					asd = true;
				};
				if (send(SecondClientSocket, &b, 1, 0) == SOCKET_ERROR) { errorFunc("send11"); };
				if (send(FirstClientSocket, poleInString, sizeof(poleInString), 0) == SOCKET_ERROR) {
					errorFunc("send12");
				};
				if (send(FirstClientSocket, &b, 1, 0) == SOCKET_ERROR) { errorFunc("send13"); };
				if (asd == true) break;
			}


		}
		closesocket(server);
		closesocket(FirstClientSocket);
		closesocket(SecondClientSocket);
	}


	fout << "baaad " << endl;
	fout.close();
	serviceStatus.dwCheckPoint++;
	serviceStatus.dwCurrentState = SERVICE_STOPPED;
	SetServiceStatus(ServiceController, &serviceStatus);
}

VOID WINAPI ServiceCtrlHandler(DWORD control, DWORD eventType, LPVOID eventData, LPVOID eventContext) {
	switch (control) {
	case SERVICE_CONTROL_STOP:
		fout.close();
		closesocket(server);
		serviceStatus.dwCheckPoint++;
		serviceStatus.dwCurrentState = SERVICE_STOPPED;
		if (!SetServiceStatus(ServiceController, &serviceStatus)) {
			fout << "SetServiceStatus3 error" << WSAGetLastError() << endl;
			closesocket(server);
			fout.close();
		}
		break;
	default:
		serviceStatus.dwCheckPoint++;
		if (!SetServiceStatus(ServiceController, &serviceStatus)) {
			fout << "SetServiceStatus3 error" << WSAGetLastError() << endl;
			closesocket(server);
			fout.close();
		}
		break;
	}
}