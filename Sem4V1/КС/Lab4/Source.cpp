#pragma comment(lib,"ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <string>
#include <winsock2.h>
#include <windows.h>
#include <iostream>
#include <fstream>
using namespace std;
/*
Чтобы сохранить HTML-страницу, необходимо
корректно получить ответ на отправленный запрос,
который можно отправить, утановив соединение
через WinSock, зная корректный URL страницы:
*/
string Manage(string response) {
	if (response.find("200 OK") != string::npos)
		return response.substr(response.find("\r\n\r\n")).erase(0, response.find_first_not_of("\t\n\v\f\r "));
	string codes[] = { "404 Not Found",
					"400 Bad Request",
					"408 Request Timeout",
					"500 Internal Server Error",
					"502 Bad GateWay" };
	for (string code : codes)
		if (response.substr(0, response.find("\r\n\r\n")).find(code) != string::npos)
			return code;
	return response;
}
string Response(string url) {
	string main_page = url, subpage = "/";
	if (url.find('/') != string::npos) {
		main_page = url.substr(0, url.find('/'));
		subpage = url.substr(url.find('/'));
	}
	string http_req = "GET http://" + subpage + " HTTP/1.1\r\nHost: " + main_page + "\r\nConnection: close\r\n\r\n";
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		cout << "WSAStartup failed.\n";
		system("pause");
		exit(-1);
	}

	SOCKET Socket;
	SOCKADDR_IN sock_addr;
	Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	hostent* hostInfo = gethostbyname(main_page.c_str());
	sock_addr.sin_port = htons(80);
	sock_addr.sin_family = AF_INET;
	sock_addr.sin_addr.s_addr = *((unsigned long*)hostInfo->h_addr);

	if (connect(Socket, (SOCKADDR*)(&sock_addr), sizeof(sock_addr)) != 0) {
		cerr << "Error in socket connection\n";
		system("pause");
		exit(-1);
	}

	send(Socket, http_req.c_str(), strlen(http_req.c_str()), 0);

	int data_size;
	char buffer[256];
	string answer;

	while ((data_size = recv(Socket, buffer, sizeof(buffer), 0)) > 0)
		answer += buffer;

	closesocket(Socket);
	WSACleanup();
	return answer;
}
bool IsCorrect(string url) {
	int pos = url.find('.');
	return !(pos == string::npos || url.substr(pos + 1, url.length() - pos).empty() || url.substr(0, pos).empty());
}
int main() {
	ofstream f;
	f.open("file.txt");

	string url;
	cout << "Input valid url:\n";
	cin >> url;
	if (!IsCorrect(url)) {
		cout << "Invalid url\n";
		system("pause");
		return 0;
	}
	f << Manage(Response(url));
	cout << "The response has been written to the file\n";
	f.close();

	system("pause");
	return 0;
}