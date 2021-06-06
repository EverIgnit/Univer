#include "Header.h"
#include <algorithm>
#include <iterator>
#include <string>
/* ===== Оператор для сравнения двух студентов между собой ===== */
bool operator<(TRAIN train1, TRAIN train2) {
	/* сравниваем по номеру студенческого билета */
	bool result = train1.timeo < train2.timeo;
	return result;
}
/* =========== Метод для упорядочения списка группы ============ */
void SETOFTR::sort() {
	/* выполняем сортировку контейнера Students с помощью библиотечного алгоритма sort */
	std::sort(this->trains.begin(), this->trains.end());
	/* по умолчанию порядок сортировки контейнера определяется перегруженным оператором < */
}
ostream& SETOFTR::find(ostream& out, SETOFTR& setof, string st) {
	vector<TRAIN>::iterator iter;
	iter = setof.trains.begin();
	while (iter != setof.trains.end()) {
		if ((*iter).getlast()==st)
			cout << *iter << endl;
		iter++;
	}
	return out;
}
istream& operator >> (istream &in, TRAIN &train) {
	in >> train.num;
	in >> train.last;
	in >> train.timeo;
	in >> train.timei;
	return in;
}
ostream& operator << (ostream &out, TRAIN &train) {
	out << "Номер поезда: " << train.num << ", Последняя станция поезда: " << train.last
		<< ",\nВремя отправления поезда: " << train.timeo << ", Время прибытия поезда: "
		<< train.timei << endl;
	return out;
}
/* ======= Ввод информации о группе из входного потока ========= */
istream& operator >> (istream& in, SETOFTR& setof) {
	in >> setof.Name;
	setof.trains.clear();
	/* ввод списка студентов с использованием итераторов */
	istream_iterator<TRAIN> in_iter(in);
	istream_iterator<TRAIN> in_end;
	while (in_iter != in_end) {
		TRAIN train = *in_iter;
		setof.trains.push_back(train);
		in_iter++;
	}
	return in;
}
/* ====== Вывод информации о группе в выходной поток =========== */
ostream& operator<<(ostream& out, SETOFTR& setof) {
	out << "Упорядоченные по времени отправления: " << setof.Name << endl;
	/* вывод списка студентов с использованием итераторов */
	vector<TRAIN>::iterator iter;
	iter = setof.trains.begin();
	while (iter != setof.trains.end()) {
		out << *iter << endl;
		iter++;
	}
	return out;
}
/*
TRAIN sort(TRAIN *train, int n) {
	for (int i = 1; i < n; i++) if (train[i - 1].timeo > train[i].timeo) {
		swap(train[i - 1], train[i]);
		i = 0;
	}
	return *train;
}
void outstation(TRAIN*train, int n, string s, ostream &out) {
	out << "Поезд на указанной станции \n";
	for (int i = 0; i < n; i++) {
		if (train[i].last == s)
			out << train[i];
	}
	out << "\n--------------------\nОтсортированный список поездов:\n";
}
int ReadCount(istream &in) {
	int n;
	in >> n;
	return n;
}
*/
/*
TRAIN ReadTrain(istream &in) {
TRAIN train;
in >> train.num;
in >> train.last;
in >> train.timeo;
in >> train.timei;
return train;
}
*/
