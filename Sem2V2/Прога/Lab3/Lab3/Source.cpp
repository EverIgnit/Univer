#include "Header.h"
#include <windows.h>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ofstream out("out.txt");
	//out << "������� ���������� ������� (�� 20)\n";
	int n;
	ifstream in("vvod.txt");
	if (!in.is_open() || !out.is_open()) {
		out << "������ ������ � ���� " << endl;
		system("pause");
		return 0;
	}
	string st;
	getline(in, st);
	SETOFTR setof;
	/* ��������� ������ �� ����� ������ */
	in >> setof;
	/* ������� ����� */
	in.close();
	/* ����������� ������ */
	setof.sort();
	/* ������� ������ � ����� cout (�� �����) */
	cout << setof << "\n������ �� ������� " << st << ": \n\n";
	setof.find(out, setof, st);
	system("pause");
	return 0;
}
/*
	n = ReadCount(in);
	TRAIN *train = new TRAIN[n];
	for (int i = 0; i < n; i++)
		in >> train[i];
	out << "������� �������, ����� ������� ������\n";
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
