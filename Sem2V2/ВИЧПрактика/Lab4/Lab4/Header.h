#pragma once
#include <iostream>
#include <string>
using namespace std;
// ������ 1
class Print{
public:
	Print() {
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 10; j++)
				cout << j << ' ';
			cout << endl;
		}
	}
};
// ������ 2
class Table {
	int a[15][3];
public:
	void Read() {
		cout << "  ��������� ������, ������� ���������� � ����������\n����������� �� ������������, �������� � ������������ ����������\n\n�  � � �\n";
		for (int i = 0; i < 15; i++) {
			cout << i+1 << ". ";
			for (int j = 0; j < 3; j++) {
				cin >> a[i][j];
			}
		}
	}
	void Average() {
		int sum = 0;
		for (int i = 0; i < 15; i++) {
			cout << i+1 << " ���������:  " << (a[i][0] + a[i][1] + a[i][2]) / 3 << "\n";
		} 
		cout << "������� � �����������:\n";
		for (int j = 0; j < 3; j++) {
			sum = 0;
			for (int i = 0; i < 15; i++) {
				sum += a[i][j];
			}
			cout << sum / 15 << ' ';
		}
		cout << endl;

	}
};
// ������ 3
class Del {
public:
	Del() {
		cout << "������� n\n";
	}
	void Func() {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cout << i;
			for (int j = 1; j <= i; j++) {
				if (!(i%j)) {
					cout << '+';
				}
			}
			cout << endl;
		}
	}
};
// ������ 4
class Text{
public:
	Text() {
		cout << "������� �����\n";
	}
	void func() {
		string s;
		getline(cin, s, '\n');
		int max = 0;
		for (int maxtemp = 0, i = 0; i < s.size(); i++) {
			if (s[i] == s[i + 1])
				maxtemp++;
			else
			{
				maxtemp++;
				if (max < maxtemp) {
					max = maxtemp;
				}
			maxtemp = 0;
			}
		}
		cout << max << endl;
	}
};
/*
cout << "  ��������� ������, ������� ���������� � ����������\n����������� �� ������������, �������� � ������������ ����������\n\n�  � � �\n";
		int a[16][4];
		int sum = 0;
		for (int i = 1; i <= 15; i++) {
			cout << ci << ". ";
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
			cout <<"\t  " << (a[i][1] + a[i][2] + a[i][3]) / 3 <<"\n";
		}
		for (int j = 1; j <= 3; j++) {
			sum = 0;
			for (int i = 1; i <= 15; i++) {
				sum += a[i][j];
			}
			cout << sum / 15 <<' ';
		}
		cout << endl;
*/