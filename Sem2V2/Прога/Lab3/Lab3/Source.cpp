#include "Header.h"
#include <windows.h>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ofstream out("out.txt");
	//out << "Введите количество поездов (до 20)\n";
	int n;
	ifstream in("vvod.txt");
	if (!in.is_open() || !out.is_open()) {
		out << "Ошибка записи в файл " << endl;
		system("pause");
		return 0;
	}
	string st;
	getline(in, st);
	SETOFTR setof;
	/* прочитать группу из этого потока */
	in >> setof;
	/* закрыть поток */
	in.close();
	/* упорядочить группу */
	setof.sort();
	/* вывести группу в поток cout (на экран) */
	cout << setof << "\nПоезда на станции " << st << ": \n\n";
	setof.find(out, setof, st);
	system("pause");
	return 0;
}
/*
	n = ReadCount(in);
	TRAIN *train = new TRAIN[n];
	for (int i = 0; i < n; i++)
		in >> train[i];
	out << "Введите станцию, чтобы увидеть поезда\n";
	string s;
	in >> s;
	in.close();
	sort(train, n);
	outstation(train, n, s, out);
	for (int i = 0; i < n; i++)
		out << train[i];
	out.close();
	delete[] train;
	system("pause");
	return 0;
}
*/
