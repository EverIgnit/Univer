#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//������ �������
	/*
	int n1, n2;
	cout << "���� ������ S1, S2 � ����������� ����� N1, N2. ���������� ������������ �� ���� ����� �����,\n���������� ������ N1 �������� ������ S1 � ��������� N2 �������� ������ S2 /n(� ��������� �������)\n\n ������� 1. ������� 2 ������ � 2 �����\n";
	char str[100], str2[100];
	cin.getline(str, 100);
	cin.getline(str2, 100);
	cin >> n1 >> n2;
	if (n1 > sizeof(str)) {
		cout << "���������� �������� ��� ������ ��������� ���������� �������� ������\n";
		system("pause");
		return 0;
	}
	if (n1 > sizeof(str)) {
		cout << "���������� �������� ��� ������ ��������� ���������� �������� ������\n";
		system("pause");
		return 0;
	}
	string s1(str);
	if (n1 > sizeof(str2)) {
		cout << "���������� �������� ��� ������ ��������� ���������� �������� ������\n";
		system("pause");
		return 0;
	}
	const string s2(str2);
	cout << s1.replace(n1, s1.size()-n1, s2, n1, n2) << endl;
	*/
	//������ �������
	/*
	vector<int> v;
	cout << "\n� ����� ������������������ ������� ������ ���� \n��� ������������� �������� ��������, ����� ��� ������� ��������,\n����� ��� �������������(� ����������� ��������� �������������� �������).\n\n������� ���������� ��������� ������������������, � ����� �� �����\n";
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