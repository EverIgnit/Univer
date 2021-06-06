#include <string>
#include <vector>
#include <iostream>
using namespace std;
class LAND {
	int y;
	int x;
	int b;
	int a;
	/* ������������� ������� - ��������� */
	friend istream& operator >> (istream& in, LAND& land);
	friend bool operator<(LAND land1, LAND land2);
public:
	int getx() {
		return x;
	}
	int gety() {
		return y;
	}
	int geta() {
		return a;
	}
	int getb() {
		return b;
	}
};
class SetOfLands {
	vector<LAND> lands; /* ��������� (������)*/
public:
	void sort(); /* ������������ ������*/
	vector<LAND> getvector() {
		return lands;
	}
	friend istream& operator >> (istream& in, SetOfLands& set);
};
