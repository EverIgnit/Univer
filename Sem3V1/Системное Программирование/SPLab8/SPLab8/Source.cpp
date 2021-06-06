#include <windows.h>
#include <iostream>

using namespace std;
int N = 0, K = 0, Size = 0;
unsigned Sum = 0;
unsigned* Array = NULL;
CRITICAL_SECTION cr_s;

DWORD WINAPI SummWorker(LPVOID lpStartNumber) {
	unsigned st = *((unsigned*)lpStartNumber);
	unsigned partSum = 0;
	EnterCriticalSection(&cr_s);
	for (unsigned i = Size * st; i < Size*(st + 1) && i < N; i++) {
		partSum += Array[i];
	}
	Sum = Sum + partSum;
	LeaveCriticalSection(&cr_s);
	return 0;
}

int main() {
	InitializeCriticalSection(&cr_s);

	HANDLE* hThreads = NULL;

	setlocale(0, "");

	__try {
		cout << "Количество элементов массива?" << endl << "> ";
		cin >> N;
		if (N <= 0)
			RaiseException(1, 0, 0, NULL);
		else {
			cout << "Количество потоков программы?" << endl << "> ";
			cin >> K;
			if ((K <= 0) || (K > N) || (K > 63))
				RaiseException(2, 0, 0, NULL);
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		cerr << "Ошибка параметров. Завершение. Код исключения: " << GetExceptionCode() << endl;
		system("pause");
		return 1;
	}

	Array = new unsigned[N];
	hThreads = new HANDLE[K];
	Size = (N / K) + 1;

	for (unsigned i = 0; i<N; i++)
		Array[i] = i;

	for (unsigned i = 0; i<K; i++) {
		unsigned *n = new unsigned(i);
		hThreads[i] = CreateThread(NULL, 0, SummWorker, (LPVOID)n, 0, NULL);
	}
	WaitForMultipleObjects(K, hThreads, TRUE, INFINITE);

	DeleteCriticalSection(&cr_s);

	cout << "Сумма элементов массива равна " << Sum << endl;

	for (unsigned i = 0; i < K; i++)
		CloseHandle(hThreads[i]);

	system("pause");
	return 0;
}