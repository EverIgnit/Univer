#include <windows.h>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
void outp(vector<double>::iterator iter, vector<double> v) {
	cout << "Последовательность после сортировки: " << endl;
	iter = v.begin();
	while (iter < v.end()) {
		cout << *iter << ' ';
		iter++;
	}
	cout << endl;
}
void inp(vector<double>&v) {
	cout << "Введите последовательность чисел (int / double):\n ";
	istream_iterator<double> cin_iter(cin);
	istream_iterator<double> cin_end;
	while (cin_iter != cin_end) {
		double x = *cin_iter;
		v.push_back(x);
		cin_iter++;
	}
}
int Summary(vector<double>&v) {
	// объявление итератора - указателя на элемент вектора
	vector<double>::iterator iter, iter2;
	// начинаем с начала вектора
	iter = v.begin();
	// Поиск отрицательного элемента
	while (iter < v.end()) {
		if (*iter < 0)
			break;
		if (iter == v.end() - 1) {
			cout << "Отрицательных элементов нет!\n";
			return 0;
		}
		iter++;
	}
	// начинаем с конца вектора
	for (iter2 = iter + 1; iter2 < v.end(); iter2++)
		if (*iter2 < 0)
			break;
	double sum = 0;
	for (iter++; iter < iter2; iter++)
		sum += *iter;
	return sum;
}
void sort(vector<double>&v, vector<double>::iterator iter) {
	double temp;
	vector<double>::iterator iter2;
	for (iter; iter < v.end(); iter++) {
		iter2 = iter;
		temp = *iter2;
		for (iter2 = iter; (iter2 > v.begin()) && (temp < *(iter2 - 1)); iter2--) {
				*iter2 = *(iter2 - 1);
		}
		*(iter2) = temp;
	}
}
void sort2(vector<double>&v, vector<double>::iterator iter) {
	double temp;
	vector<double>::iterator iter2;
	for (iter; iter < v.end(); iter++) {
		iter2 = iter;
		temp = *iter2;
		for (iter2 = iter; (iter2 > v.begin()) && (temp > *(iter2 - 1)); iter2--) {
			*iter2 = *(iter2 - 1);
		}
		*(iter2) = temp;
	}
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<double> v;
	vector<double>::iterator iter, iter1, iter2;
	inp(v);
	cout << "Sum: " << Summary(v) << endl;
	iter1 = v.begin() + 1;
	sort(v, iter1);
	outp(iter, v);
	sort2(v, iter1);
	outp(iter, v);
	system("pause");
	return 0;
}
