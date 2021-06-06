#include <windows.h>
#include <iostream>

using namespace std;
int N = 0, K = 0, Size = 0;
int Sum = 0;
int* Array = NULL;
CRITICAL_SECTION cr_s;

DWORD error(DWORD a) {
	if (a == 1) {
		cout << "Введите корректное значение количества элементов массива\nИначе исправление пройдёт автоматически" << endl << "> ";
		cin >> N;
		if (N <= 0)
			N = 1;
	}
	else
		if (a == 2) {
			cout << "Введите корректное значение количества потоков программы\nИначе исправление пройдёт автоматически" << endl << "> ";
			cin >> K;
			if (K <= 0)
				K = 1;
			else
				if (K > N)
					K = N;
		}
	return EXCEPTION_EXECUTE_HANDLER;
}

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
	}
	__except (error(GetExceptionCode())) {
		cout << "Исключение исправлено." << endl;
	}
	__try {
			cout << "Количество потоков программы?" << endl << "> ";
			cin >> K;
			if ((K <= 0) || (K > N) || (K > 63))
				RaiseException(2, 0, 0, NULL);
	}
	__except (error(GetExceptionCode())) {
		cout << "Исключение исправлено." << endl;		
	}
	Size = N / K + 1;
	Array = new int[N];
	hThreads = new HANDLE[K];

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