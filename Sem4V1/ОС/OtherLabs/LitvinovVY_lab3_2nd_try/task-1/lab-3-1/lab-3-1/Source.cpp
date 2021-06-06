#include<Windows.h>
#include<iostream>
#include<string.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "");
	DWORD infMutex = 0, countOfHandles = 0;//�������� ����� JS xD

	//�������� ���������� �������� ������������, ������������� ���������� ��������.
	if (!GetProcessHandleCount(GetCurrentProcess(), &countOfHandles)) {
		cout << "�� ������� �������� ������� ���������� ��������" << endl;
		return 0;
	}
	cout << "������� ������� �����[" << countOfHandles <<"] ������������" << endl;
	//�������� ������������ ��� ��������
	SECURITY_ATTRIBUTES sa;
	sa.bInheritHandle = FALSE;//���������� ��������-����������� �� ������������ ���������� ��� �������� ������ ��������? 
	sa.lpSecurityDescriptor = NULL;//������������ ������ � �������
	//NULL - ������ ��-���������

	HANDLE mutex = CreateMutex(&sa, FALSE, FALSE);
	if (mutex == INVALID_HANDLE_VALUE) {
		cout << "������ �������� ��������!" << endl;
		return 0;
	}
	cout << "������� ������!" << endl;
	//������� ���������� ��������
	if (!GetHandleInformation(mutex, &infMutex)) {
		cout << "������ ��������� ���������� ��������" << endl;
		return 0;
	}
	cout << "�������� ���������� ��������(�������� ����)" << endl;
	if (infMutex == 0)									cout << "�� �����������, ��� �������� �� ���������!" << endl;
	//���� ���� ������ ����������, �������� �������, 
	//��������� �������� CreateProcess � ���������� bInheritHandles 
	//������������� � �������� ������ (TRUE) ��������� ���������� �������. 
	if (infMutex == HANDLE_FLAG_INHERIT)				cout << "�������� ������� ��������� ���������� �������" << endl;
	//���� ���� ������ ����������, ����� ������� CloseHandle �� ����� ��������� ���������� �������.
	if (infMutex == HANDLE_FLAG_PROTECT_FROM_CLOSE)		cout << "������ �������� �������" << endl;

	SetHandleInformation(mutex, HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT);
	//������� ���������� �������� ������ ���
	if (!GetHandleInformation(mutex, &infMutex)) {
		cout << "�� ������� �������� ���������� ��������(2)" << endl;
		return 0;
	}
	cout << "�������� ���������� ��������(2)(�������� ����)" << endl;

	if (infMutex == 0)									cout << "�� �����������, ��� �������� �� ���������!" << endl;
	if (infMutex == HANDLE_FLAG_INHERIT)				cout << "�������� ������� ��������� ���������� �������" << endl;
	if (infMutex == HANDLE_FLAG_PROTECT_FROM_CLOSE)	cout << "������ �������� �������" << endl;

	//�������� ���������� �������� ������������, ������������� ���������� ��������.
	if (!GetProcessHandleCount(GetCurrentProcess(), &countOfHandles)) {
		cout << "�� ������� �������� ������� ���������� ��������" << endl;
		return 0;
	}
	cout << "������� ������� �����[" << countOfHandles << "] ������������" << endl;
	system("pause");
	return 0;
}