#include "Header.h"
#include <algorithm>
#include <iterator>
#include <string>
/* ===== �������� ��� ��������� ���� �������� ����� ����� ===== */
bool operator<(LAND land1, LAND land2) {
	/* ���������� �� ������ ������������� ������ */
	bool result = land1.x < land2.x;
	return result;
}
/* =========== ����� ��� ������������ ������ ������ ============ */
void SetOfLands::sort() {
	/* ��������� ���������� ���������� � ������� ������������� ��������� sort */
	std::sort(this->lands.begin(), this->lands.end());
	/* �� ��������� ������� ���������� ���������� ������������ ������������� ���������� < */
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
	/* ���� ������ ��������� � �������������� ���������� */
	istream_iterator<LAND> in_iter(in);
	istream_iterator<LAND> in_end;
	while (in_iter != in_end) {
		LAND land = *in_iter;
		set.lands.push_back(land);
		in_iter++;
	}
	return in;
}
