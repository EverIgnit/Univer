#include <windows.h>
#include <iostream>

using namespace std;
// Глобальные (т.е. разделяемые всеми потоками) переменные:
// N - размер массива; K - количество потоков; 
// size - размер "проции" массива для обработки одним потоком
// Sum - накопительная переменная для суммы элементов массива Array
unsigned N = 0, K = 0, Size = 0;
unsigned Sum = 0;
unsigned* Array = NULL;

// Функция, запускаемая в потоках
DWORD WINAPI SummWorker(LPVOID lpStartNumber) {
	unsigned st = *((unsigned*)lpStartNumber);
	unsigned partSum = 0;
	for (unsigned i = Size * st; i<Size*(st + 1) && i < N; i++)
		partSum += Array[i];
	Sum = Sum + partSum;
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
	Array = new unsigned[N];
	hThreads = new HANDLE[K];
	Size = N / K + 1;

	//заполнение массива
	for (unsigned i = 0; i<N; i++)
		Array[i] = i;

	//поиск суммы
	for (unsigned i = 0; i<K; i++) {
		unsigned *n = new unsigned(i);
		hThreads[i] = CreateThread(NULL, //security atributes
			0, //the stack size of new thread in bytes
			SummWorker, //pointer to function – the entry point to the thread
			(LPVOID)n,  //pointer to a thread function argument
			0, //the state of the thread after launch; 0 - start immediately after creation;
			NULL //pointer to a variable that receives a thread ID
		);
	}

	WaitForMultipleObjects(K, //array size
		hThreads, //handle
		TRUE, //transition to the alarm state of all objects
		INFINITE //waiting time in milliseconds
	);

	cout << "Сумма элементов массива равна " << Sum << endl;
	system("pause");
	return 0;
}

/*Unterlocked функции - синхронизируют доступ к переменной, совместно используемой несколькими потоками.
Их цель состоит в том, чтобы предотвратить поток от вытеснения во время увеличения или проверки переменной.
Потоки различных процессов могут использовать эти функции до тех пор, пока их переменные совместно используют память.

SRWLock представляет тонкую блокировку чтения и записи. Блокировки потоков чтения/записи используется для синхронизации
доступа между потоками для объекта или ресурса.*/