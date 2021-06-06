#include <string>
#include <vector>
#include <iostream>
using namespace std;
/* --------- описание объектного типа данных СТУДЕНТ ----------- */
class TRAIN {
	int num;
	string last;
	int timeo;
	int timei;
	/* дружественные функции - операторы */
	friend ostream& operator<< (ostream &out, TRAIN &train);
	friend istream& operator >> (istream& in, TRAIN& train);
	friend bool operator<(TRAIN train1, TRAIN train2);
public:
	string getlast() {
		return last;
	}
};
/* --------- описание объектного типа данных ГРУППА ------------ */
class SETOFTR {
	string Name; /* Название Набора поездов */
	vector<TRAIN> trains; /* Контейнер (вектор) поездов */
public:
	void sort(); /* Упорядочение списка поездов */
	ostream& find(ostream& out, SETOFTR& setof, string st); /* Вывод поездов по станции */
	/* дружественные функции - операторы */
	friend ostream& operator<<(ostream& out, SETOFTR& setof);
	friend istream& operator >> (istream& in, SETOFTR& setof);
};
/*
TRAIN inone();
void outstation(TRAIN*train, int n, string s, ostream &out);
int ReadCount(istream &in);
TRAIN ReadTrain(istream &in);
*/
