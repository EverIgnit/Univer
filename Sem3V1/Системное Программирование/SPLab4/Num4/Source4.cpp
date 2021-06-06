#include <windows.h>
#include <iostream>

using namespace std;
unsigned N = 0, K = 0, Size = 0;
unsigned Sum = 0;
unsigned* Array = NULL;
unsigned* Thread = NULL;
HANDLE hS;

DWORD WINAPI SummWorker(LPVOID lpStartNumber) {
	unsigned st = *((unsigned*)lpStartNumber);
	unsigned partSum = 0;
	for (unsigned i = Size * st; i < Size*(st + 1) && i < N; i++)
		partSum += Array[i];
	WaitForSingleObject(hS, INFINITE);
	Sum = Sum + partSum;
	ReleaseSemaphore(hS, //the handle of the semaphore
		1, //positive number by which the semaphore value is increased
		NULL //previous value of the semaphore
	);
	return 0;
}

int main() {
	HANDLE* hThreads = NULL;

	//system("chcp 1251");
	setlocale(0, "");

	cout << "Количество элементов массива?" << endl << ":";
	cin >> N;
	cout << "Количество потоков программы?" << endl << ":";
	cin >> K;
	if ((N <= 0) || (K <= 0) || (K>N) || (K>63)) {
		cerr << "Ошибка параметров. Завершение." << endl;
		system("pause");
		return 1;
	}

	hS = CreateSemaphore(NULL, // security atributes
		1, //the initial value of the semaphore
		1,  //the maximum value of the semaphore
		NULL //name semaphore
	);

	if (!hS == NULL) {
		Array = new unsigned[N];
		hThreads = new HANDLE[K];
		Size = N / K + 1;

		Thread = new unsigned[K];
		for (unsigned i = 0; i < K; i++)
			Thread[i] = i;

		for (unsigned i = 0; i < N; i++)
			Array[i] = i;

		for (unsigned i = 0; i < K; i++) {
			unsigned *n = new unsigned(i);
			hThreads[i] = CreateThread(NULL, 0, SummWorker, (LPVOID)n, 0, NULL);
		}
		WaitForMultipleObjects(K, hThreads, TRUE, INFINITE);

		for (unsigned i = 0; i < K; i++)
			CloseHandle(hThreads[i]);

		cout << "Сумма элементов массива равна " << Sum << endl;
		system("pause");
	}
	else
		cerr << "Ошибка создания семафора" << endl;
	return 0;
}

/*Семафор — объект, ограничивающий количество потоков, которые могут войти в заданный участок кода.
Семафоры используются для синхронизации и защиты передачи данных через разделяемую память, а также для синхронизации
работы процессов и потоков. Семафор - позволяет остановить выполнение потока до тех пор, пока он не получит сигнала
от другого потока о том, что работу можно продолжать, т. е. позволяет блокировать одновременное выполнение потоков,
которым вместе выполняться нельзя.*/