#include "Header.h"
#include <algorithm>
#include <iterator>
#include <string>
/* ===== Оператор для сравнения двух участков между собой ===== */
bool operator<(LAND land1, LAND land2) {
	/* сравниваем по номеру студенческого билета */
	bool result = land1.x < land2.x;
	return result;
}
/* =========== Метод для упорядочения списка группы ============ */
void SetOfLands::sort() {
	/* выполняем сортировку контейнера с помощью библиотечного алгоритма sort */
	std::sort(this->lands.begin(), this->lands.end());
	/* по умолчанию порядок сортировки контейнера определяется перегруженным оператором < */
}
istream& operator >> (istream &in, LAND &land) {
	in >> land.y;
	in >> land.x;
	in >> land.b;
	in >> land.a;
	return in;
}
istream& operator >> (istream& in, SetOfLands& set) {
	set.lands.clear();
	/* ввод списка студентов с использованием итераторов */
	istream_iterator<LAND> in_iter(in);
	istream_iterator<LAND> in_end;
	while (in_iter != in_end) {
		LAND land = *in_iter;
		set.lands.push_back(land);
		in_iter++;
	}
	return in;
}
