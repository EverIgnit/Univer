#include <string>
#include <vector>
#include <iostream>
using namespace std;
/* --------- �������� ���������� ���� ������ ������� ----------- */
class TRAIN {
	int num;
	string last;
	int timeo;
	int timei;
	/* ������������� ������� - ��������� */
	friend ostream& operator<< (ostream &out, TRAIN &train);
	friend istream& operator >> (istream& in, TRAIN& train);
	friend bool operator<(TRAIN train1, TRAIN train2);
public:
	string getlast() {
		return last;
	}
};
/* --------- �������� ���������� ���� ������ ������ ------------ */
class SETOFTR {
	string Name; /* �������� ������ ������� */
	vector<TRAIN> trains; /* ��������� (������) ������� */
public:
	void sort(); /* ������������ ������ ������� */
	ostream& find(ostream& out, SETOFTR& setof, string st); /* ����� ������� �� ������� */
	/* ������������� ������� - ��������� */
	friend ostream& operator<<(ostream& out, SETOFTR& setof);
	friend istream& operator >> (istream& in, SETOFTR& setof);
};
/*
TRAIN inone();
void outstation(TRAIN*train, int n, string s, ostream &out);
int ReadCount(istream &in);
TRAIN ReadTrain(istream &in);
*/
