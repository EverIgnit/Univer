//��������� ����
#include "Header.h"
#include <iostream>
#include <Windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// ������ 1
	/*���� ����������� ������������ � ��������, ������� ���������� �����������.
	�� ������ � ������ �������� ��� �������� : "����� ����� �������� - ��� ���������� ���������� �����, � ������������ ����� � �������� ���� ����� ����� ��
	�� ����� ���������� �����". �� ����� ��������� ��� ������ ����� ��������?*/
	/*
	Number A;
	*/
	// ������ 2
	/*��� ������ ������� ��������� (������-����-����� ) ����. ������ ������
	������ ���� ���� ������ ������: ������ ��������� �� 1/3 ���� ����������.
	������� � ������ ����� ���� ������ �����, ���� ��� ������ ������� ����
	�� ����� 1 � 50 �� � ������ ������ - 3 ���� �������� �����?
	�� ���� ��� ���� 5 � �����, � ��������� ������� ���������� 2,2 ���� �� 1 ��.
	� ����� ����� 200 � �����.*/
	/*
	Scarf S;
	*/
	// ������ 3
	//�������������, ������� ����� �� ���������������� - 6.110 � 7.120
	/**/
	cout << "������� �������� �����, ����� ����� ��� ��������\n";
	int x, a;
	cin >> x >> a;
	Num s(x);
	cout << "�)\t" << s.numa() <<
		"\n�)\t" << s.numb();
	cout << "\n�)\t" << s.numv(a) <<
		"\n�)\t" << s.numg() <<
		"\n�)\t" << s.numd() << endl;

	/**/
	// ������ 4
	/*	cout << "������� ����������� ����� ��� �������� �� �������������\n";
	int a;
	cin >> a;
	CheckSorersh B(a);*/
	system("pause");
	return 0;
}