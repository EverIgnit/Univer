#include <windows.h>
#include <iostream>

using namespace std;
int N = 0, K = 0;
int Sum = 0;
TCHAR* s = NULL;
CRITICAL_SECTION CS;
TCHAR* digits = "1234567890";

DWORD WINAPI CalcDigits(LPVOID lpStartNumber) {
	EnterCriticalSection(&CS);
	unsigned int st = ((unsigned int)lpStartNumber);

	for (unsigned int i = st; i < N; i += K)
	{
		for (short j = 0U; j < 9; j++)
		{
			if (s[i] == digits[j]) {
				Sum++;
				continue;
			}
		}
	}
	LeaveCriticalSection(&CS);
	return 0;
}

int main()
{
	setlocale(0, "");
	HANDLE* hThreads = NULL;
	InitializeCriticalSection(&CS);
	cout << "Количество элементов строки?" << endl << ":";
	cin >> N;
	cout << "Количество потоков программы?" << endl << ":";
	cin >> K;
	if ((N <= 0) || (K <= 0) || (K > N) || (K > 63)) {
		cerr << "Ошибка. Некорректные значения." << endl;
		system("pause");
		return 1;
	}

	s = new TCHAR[N];
	hThreads = new HANDLE[K];
	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < K; i++)
	{
		hThreads[i] = CreateThread(NULL, 0, CalcDigits, (LPVOID)i, 0, NULL);
		WaitForSingleObject(hThreads[i], INFINITE);
	}
	WaitForMultipleObjects(K, hThreads, TRUE, INFINITE);
	cout << "Количество цифр в строке: " << Sum << endl;
	system("pause");
	return 0;
}