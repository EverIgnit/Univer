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

	cout << "Количество элементов массива?" << endl << ":";
	cin >> N;
	cout << "Количество потоков программы?" << endl << ":";
	cin >> K;
	if ((N <= 0) || (K <= 0) || (K>N) || (K>63)) {
		cerr << "Ошибка параметров. Завершение." << endl;
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
			cerr << "Ошибка создания мьютекса." << endl;
			return 0;
	}
	WaitForMultipleObjects(K, hThreads, TRUE, INFINITE);

	for (unsigned i = 0; i < K; i++)
		CloseHandle(hThreads[i]);

	cout << "Сумма элементов массива равна " << Sum << endl;
	system("pause");
	return 0;
}

/* Мьютекс(«взаимное исключение») — аналог одноместного семафора, служащий в программировании для синхронизации
одновременно выполняющихся потоков. Мьютекс - служит для совместного использования неких данных, т. е.
он не блокирует выполнение другого потока в принципе, но запрещает прерывать текущий поток до выполнения некоторых действий.
Мьютексы — это простейшие двоичные семафоры, которые могут находиться в одном из двух состояний — отмеченном или неотмеченном
(открыт и закрыт соответственно). Когда какой-либо поток, принадлежащий любому процессу, становится владельцем объекта mutex,
последний переводится в неотмеченное состояние. Если задача освобождает мьютекс, его состояние становится отмеченным.
Задача мьютекса — защита объекта от доступа к нему других потоков, отличных от того, который завладел мьютексом.
В каждый конкретный момент только один поток может владеть объектом, защищённым мьютексом. Если другому потоку будет нужен доступ к переменной,
защищённой мьютексом, то этот поток блокируется до тех пор, пока мьютекс не будет освобождён.
Мьютекс отличается от семафора тем, что он предоставляет доступ только одному потоку в то время как семафор может предоставлять
доступ одновременно нескольким потокам.*/