#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
using namespace std;
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	ofstream out1("Num1_out.txt");
	ofstream out2("Num2_out.txt");
	ofstream out3("Num3_out.txt");
	ifstream in1_1("Num1_1.txt");
	ifstream in1_2("Num1_2.txt");
	ifstream in2("Num2_in.txt");
	ifstream in3("Num3_in.txt");
	ifstream in4_1("Num4_1.txt");
	ifstream in4_2("Num4_2.txt");
	if ((!in1_1.is_open()) || (!in1_2.is_open()) || (!out1.is_open()) || (!in2.is_open()) || (!in3.is_open()) || (!in4_1.is_open()) || (!in4_2.is_open()) || (!out3.is_open()) || (!out2.is_open())) {
		cout << "�������� ������!\n";
		system("pause");
		return 0;
	}

	// ������ 1
	/*
	int n; // ���������� ����� � �����
	bool AisTrueBisFalse; // ��������� ����� �) ��� �)
	in1_1 >> n >> AisTrueBisFalse; // ��������� ���������� � ������
	int *x = new int[n], *y = new int[n]; // � ��� ������� ���������� �������� �����
	for (int i = 0; i < n; i++) {
		in1_1 >> x[i];
		in1_2 >> y[i];
		if (AisTrueBisFalse)
			out1 << x[i] - y[i] << '\n';
		else
			out1 << min(x[i], y[i]) << '\n';
	}
	delete[]x;
	delete[]y;
	*/
	in1_1.close();
	in1_2.close();
	out1.close();

	// ������ 2
	/*
	int n; // ���������� ������� ��� ����������
	in2 >> n; // ��������� �� ����������
	string *Cities = new string[n]; // ������ �������� �������
	double *people = new double[n]; // ������ ��������� �������
	for (int i = 0; i < n; i++) {
		//getline(in2, Cities[i], '\n'); // ��������� �������� ������
		in2 >> Cities[i];
		out2 << Cities[i]; // ������� �������� ������
		in2 >> people[i]; // ��������� ���������
		out2 << '\n';
		out2 << people[i] * 1.05;
		out2 << '\n'; // ������� ����������� �� 5% ���������
	}

	delete[]Cities;
	delete[]people;
	*/
	in2.close();
	out2.close();

	// ������ 3
	/*
	out3.clear();
	bool PointA;
	in3 >> PointA;
	string *Lines = new string[50];
	getline(in3, Lines[0], '\n');
	int i;
	for (i = 0; in3; i++)
		getline(in3, Lines[i], '\n');
	if (PointA)
	{
		Lines[5] = "------------";
	}
	else
	{
		int j = i;
		bool done = false;
		while (j >= 0)
		{
			for (int l = 0; l < Lines[j].size(); l++)
			{
				if (Lines[j][l] == ' ')
					break;
				if (l == Lines[j].size() - 1)
				{
					Lines[j + 1] = "-----------";
					done = true;
				}
			}
			if (j == 0 && done == false)
			{
				Lines[i - 1] = "-----------";
			}
			j--;
		}
	}
	for (int j = 0; j < i; j++)
		out3 << Lines[j] << endl;

	delete[]Lines;
	*/
	in3.close();
	out3.close();
	// ������ 4
	/*
	string *Firstfile = new string[50], *Secondfile = new string[50];
	int i = 0;
	bool Thesame = true;
	while (in4_1 || in4_2)
	{
		getline(in4_1, Firstfile[i], '\n');
		getline(in4_2, Secondfile[i], '\n');
		if (Firstfile[i] != Secondfile[i])
		{
			cout << "����� ���������� ���� �� ����� �� ������ �" << i + 1 << endl;
			Thesame = false;

			break;
		}
		i++;
	}
	if (Thesame)
	{
		cout << "������ ������ ���������\n";
	}
	*/
	in4_1.close();
	in4_2.close();
	system("pause");
	return 0;
}
