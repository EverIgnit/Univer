#pragma once
#include <iostream>
#include <string>
using namespace std;
// Задача 1
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
// Задача 2
class Table {
	int a[15][3];
public:
	void Read() {
		cout << "  Использую пробел, введите информацию о пятнадцати\nспортсменах по обязательной, короткой и произвольной программах\n\n№  О К П\n";
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
			cout << i+1 << " спортсмен:  " << (a[i][0] + a[i][1] + a[i][2]) / 3 << "\n";
		} 
		cout << "Среднее в дисциплинах:\n";
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
// Задача 3
class Del {
public:
	Del() {
		cout << "Введите n\n";
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
// Задача 4
class Text{
public:
	Text() {
		cout << "Введите текст\n";
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
cout << "  Использую пробел, введите информацию о пятнадцати\nспортсменах по обязательной, короткой и произвольной программах\n\n№  О К П\n";
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