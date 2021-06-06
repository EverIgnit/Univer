#include "Header.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

#undef max

using namespace std;
// �������
int Music::getGenre() {
	return genre;
}
string Music::getName() {
	return name;
}
int Music::getTime() {
	return time;
}
// ����
void Song::InP() {
	getline(cin, name, ' ');
	getline(cin, author, ' ');
	int tm, ts;
	cin >> tm >> ts >> genre;
	time = tm * 60 + ts;
	getline(cin, textaughtor);
}
void Melody::InP() {
	cin >> name;
	if (name == "@@@")
		return;
	cin >> author;
	int tm, ts;
	cin >> tm >> ts >> genre;
	time = tm * 60 + ts;
	cin >> instrument;
}
PlayList::PlayList() {
	pl = new Music*[100];
	SizeP = 0;
	// ������ ����� ������� ��� ����� (true � false ��������������)
	Melody NMelody;
	Song NSong;
	Melody *NewMelody = &NMelody;
	Song *NewSong = &NSong;
	cout << "������� 1, ���� ���������� �������, 0 - ���� �����. \n����� (������ � ����� ������) ������� ��������, ������, �����������������(������, �������), \n����( 1 - ���, 2- ��������, 3 - ���, 4 - ���������), ���������� ��� 1, ������ ������ ��� 0\n��� ���������� �����, ����� ������ �������/����� ������� @@@\n";
	while (1) {
		// ������ ����� ������� ��� ����� (true � false ��������������)
		bool TmelodyFsong;
		cin >> TmelodyFsong;
		if (TmelodyFsong) { // ���� ������ �������
			// ������ ������ � �������
			NewMelody->InP();
			// ���� �������� �������� ��������� � ���������� �����, ������� �� �����
			if (NewMelody->getName() == "@@@")
				break;
			// ��������� ��������� ������� � ���������
			pl[SizeP] = NewMelody;
		}
		else {
			bool TRmelodyFAsong;
			cin >> TRmelodyFAsong;
			if (TRmelodyFAsong) { // ���� ������ �����
				// ������ ������ � �����
				NewSong->InP();
				// ���� �������� �������� ��������� � ���������� �����, ������� �� �����
				if (NewSong->getName() == "@@@")
					break;
				// ��������� ��������� ������� � ���������
				pl[SizeP] = NewSong;
			}
		}
		// �������� ���������� � ������� ����������
		SizeP++;
	}
}
// �����
void Melody::OutP() {
	cout << name << " - " << author << " (" << time / 60 << ", " << time % 60 << ") " << genre << instrument << endl;
}
void Song::OutP() {
	cout << name << " - " << author << " (" << time / 60 << ", " << time % 60 << ") " << genre << textaughtor << endl;
}
// ����� ���� � ����� ������ �������
void PlayList::ConsoleMenu() {
	cout << "�������� ��������:\n1 - ���������� ����������������� ���������\n2 - ������������� �������� �� �����\n3 - ����� ������ �� ��������� ���������\nInput:\t";
	int variant;
	cin >> variant;
	switch (variant) {
	case 2:
		Sort();
		break;
	case 3:
		cout << "������� �������� � ������� � ��������\n";
		int tm1, ts1, tm2, ts2;
		cin >> tm1 >> ts1 >> tm2 >> ts2;
		Search(tm1, ts1, tm2, ts2);
		break;
	default:
		Calc();
		break;
	}
}
// ������������� ����������������� ���������
void PlayList::Calc() {
	int sum = 0;
	for (int i = 0; i < SizeP; i++) {
		sum += pl[i]->getTime();
	}
	cout << "����������������� ���������: " << sum / 60 << ":" << sum % 60 << endl;
}
// ����� ������ �� �����������������
void PlayList::Search(int tm1, int ts1, int tm2, int ts2) {
	for (int i = 0; i < SizeP; i++) {
		// ���� ����������������� ����� ���������� � ��������, �� ������� ���
		if (pl[i]->getTime() >= tm1 * 60 + ts1&&pl[i]->getTime() <= tm2 * 60 + ts2) {
			pl[i]->OutP();
		}
	}
}
// ���������� �� �����
/*
1
����1 �����1 2 30 2 �������
1
����2 �����2 3 15 1 ������
1
����3 �����3 1 55 2 �������
1
@@@
1
*/
void PlayList::Sort() {
	// ������� �� <algorithm> ��������� �������� �� �����
	int key;
	for (int i = 0; i < SizeP; i++)
	{
		for (int j = 0; j < i - 1; j++)
		{
			key = j + 1;
			if (pl[j]->getGenre() > pl[key]->getGenre())
			{
				swap(pl[j], pl[key]);
			}
		}
	}
	// ����� ���������������� ���������
	for (int i = 0; i < SizeP; i++) {
		pl[i]->OutP();
		cout << endl;
	}
}
