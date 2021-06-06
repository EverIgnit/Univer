// ��������� ���� ��� 9, 10
#pragma once
#include <string>
#include <vector>
using namespace std;
// ����������� ����� � ������ ����� ������������, �������� � ����������� �����
class Music {
	// ��� ������������
protected:
	// ����� � ������� � �������� ��� � ����� ����������
	int time;
	// ��������
	string name;
	// �����������
	string author;
	// ����
	int genre;
public:
	// �����/�����
	virtual void InP() = 0;
	virtual void OutP() = 0;
	// �������
	int getTime();
	string getName();
	int getGenre();
};
// ����� � �����, �������� ����������� ���������� �������
class Melody : public Music {
	string instrument;
public:
	void InP();
	void OutP();
};
// ����� � �����, ���������� ���� �����
class Song : public Music {
	string textaughtor;
public:
	void InP();
	void OutP();	
};
// ������������ �����, ���������� ����� ������ � ���������� ��������
class PlayList {
	// ��������� ������
	Music **pl;
	// ������ ����������
	int SizeP;
public:
	// �����������
	PlayList();
	// ����� �� �����������������
	void Search(int, int, int, int);
	// ���������� �� ������
	void Sort();
	// ������� �����������������
	void Calc();
	// ���������� ���� ������ �������
	void ConsoleMenu();
};
