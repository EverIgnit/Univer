#include <windows.h>
#include <iostream>

using namespace std;
unsigned N = 0, K = 0, Size = 0;
unsigned Sum = 0;
unsigned* Array = NULL;
HANDLE hM;

DWORD WINAPI SummWorker(LPVOID lpStartNumber) {
		unsigned st = *((unsigned*)lpStartNumber);
		unsigned partSum = 0;
		for (unsigned i = Size * st; i < Size*(st + 1) && i < N; i++)
			partSum += Array[i];
		if (WaitForSingleObject(hM, INFINITE) == WAIT_OBJECT_0)
			Sum = Sum + partSum;
		ReleaseMutex(hM);
	}

int main() {
	HANDLE* hThreads = NULL;

	//system("chcp 1251");
	setlocale(0, "");

	cout << "���������� ��������� �������?" << endl << ":";
	cin >> N;
	cout << "���������� ������� ���������?" << endl << ":";
	cin >> K;
	if ((N <= 0) || (K <= 0) || (K>N) || (K>63)) {
		cerr << "������ ����������. ����������." << endl;
		system("pause");
		return 1;
	}

	Array = new unsigned[N];
	hThreads = new HANDLE[K];
	Size = N / K + 1;

	for (unsigned i = 0; i<N; i++)
		Array[i] = i;

	for (unsigned i = 0; i < K; i++) {
		unsigned *n = new unsigned(i);
		hThreads[i] = CreateThread(NULL, 0, SummWorker, (LPVOID)n, 0, NULL);
	}
	
		hM = CreateMutex(NULL, //security atributes
			FALSE, //flag of the initial owner
			NULL //mutex name
		);
		if (hM == NULL) {
			cerr << "������ �������� ��������." << endl;
			return 0;
	}
	WaitForMultipleObjects(K, hThreads, TRUE, INFINITE);

	for (unsigned i = 0; i < K; i++)
		CloseHandle(hThreads[i]);

	cout << "����� ��������� ������� ����� " << Sum << endl;
	system("pause");
	return 0;
}

/* �������(��������� ����������) � ������ ������������ ��������, �������� � ���������������� ��� �������������
������������ ������������� �������. ������� - ������ ��� ����������� ������������� ����� ������, �. �.
�� �� ��������� ���������� ������� ������ � ��������, �� ��������� ��������� ������� ����� �� ���������� ��������� ��������.
�������� � ��� ���������� �������� ��������, ������� ����� ���������� � ����� �� ���� ��������� � ���������� ��� ������������
(������ � ������ ��������������). ����� �����-���� �����, ������������� ������ ��������, ���������� ���������� ������� mutex,
��������� ����������� � ������������ ���������. ���� ������ ����������� �������, ��� ��������� ���������� ����������.
������ �������� � ������ ������� �� ������� � ���� ������ �������, �������� �� ����, ������� �������� ���������.
� ������ ���������� ������ ������ ���� ����� ����� ������� ��������, ���������� ���������. ���� ������� ������ ����� ����� ������ � ����������,
���������� ���������, �� ���� ����� ����������� �� ��� ���, ���� ������� �� ����� ���������.
������� ���������� �� �������� ���, ��� �� ������������� ������ ������ ������ ������ � �� ����� ��� ������� ����� �������������
������ ������������ ���������� �������.*/