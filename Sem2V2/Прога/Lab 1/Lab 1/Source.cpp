#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Первое задание
	/*
	int n1, n2;
	cout << "Даны строки S1, S2 и натуральные числа N1, N2. Необходимо сформировать из этих строк новую,\nсодержащую первые N1 символов строки S1 и последние N2 символов строки S2 /n(в указанном порядке)\n\n Задание 1. Введите 2 строки и 2 числа\n";
	char str[100], str2[100];
	cin.getline(str, 100);
	cin.getline(str2, 100);
	cin >> n1 >> n2;
	if (n1 > sizeof(str)) {
		cout << "Количество символов для чтения превышает количество символов строки\n";
		system("pause");
		return 0;
	}
	if (n1 > sizeof(str)) {
		cout << "Количество символов для чтения превышает количество символов строки\n";
		system("pause");
		return 0;
	}
	string s1(str);
	if (n1 > sizeof(str2)) {
		cout << "Количество символов для чтения превышает количество символов строки\n";
		system("pause");
		return 0;
	}
	const string s2(str2);
	cout << s1.replace(n1, s1.size()-n1, s2, n1, n2) << endl;
	*/
	//Второе задание
	/*
	vector<int> v;
	cout << "\nВ новой последовательности сначала должны идти \nвсе отрицательные элементы исходной, затем все нулевые элементы,\nзатем все положительные(с сохранением исходного относительного порядка).\n\nВведите количество элементов последовательности, а затем их самих\n";
	unsigned n;
	cin >> n;
	int temp;
	for (unsigned i = 0; i < n; i++) {
	cin >> temp;
	v.push_back(temp);
	}
	vector<int> v2;
	for (unsigned i = 0; i < v.size(); i++) {
	if (v[i] < 0) {
	v2.push_back(v[i]);
	}
	}
	for (unsigned i = 0; i < v.size(); i++) {
	if (!v[i]) {
	v2.push_back(v[i]);
	}
	}
	for (unsigned i = 0; i < v.size(); i++) {
	if (v[i] > 0) {
	v2.push_back(v[i]);
	}
	}
	for (unsigned i = 0; i < v2.size(); i++)
	cout << v2[i] << ' ';
	cout << endl;
	*/
	system("pause");
	return 0;
}