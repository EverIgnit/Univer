#include "Header.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

#undef max

using namespace std;
// Геттеры
int Music::getGenre() {
	return genre;
}
string Music::getName() {
	return name;
}
int Music::getTime() {
	return time;
}
// Ввод
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
	// Создаём класс мелодии или песни (true и false соответственно)
	Melody NMelody;
	Song NSong;
	Melody *NewMelody = &NMelody;
	Song *NewSong = &NSong;
	cout << "Нажмите 1, если добавляете мелодию, 0 - если песню. \nЗатем (каждое с новой строки) введите название, автора, продолжительность(минуты, секунды), \nжанр( 1 - рок, 2- классика, 3 - рэп, 4 - остальное), инструмент при 1, автора текста при 0\nДля завершения ввода, после выбора мелодия/песня введите @@@\n";
	while (1) {
		// Создаём класс мелодии или песни (true и false соответственно)
		bool TmelodyFsong;
		cin >> TmelodyFsong;
		if (TmelodyFsong) { // Если вводим мелодию
			// Вводим данные о мелодии
			NewMelody->InP();
			// Если название содержит информаци о завершении ввода, выходим из цикла
			if (NewMelody->getName() == "@@@")
				break;
			// Добавляем созданный элемент в контейнер
			pl[SizeP] = NewMelody;
		}
		else {
			bool TRmelodyFAsong;
			cin >> TRmelodyFAsong;
			if (TRmelodyFAsong) { // Если вводим песню
				// Вводим данные о песне
				NewSong->InP();
				// Если название содержит информаци о завершении ввода, выходим из цикла
				if (NewSong->getName() == "@@@")
					break;
				// Добавляем созданный элемент в контейнер
				pl[SizeP] = NewSong;
			}
		}
		// Изменяем информацию о размере контейнера
		SizeP++;
	}
}
// Вывод
void Melody::OutP() {
	cout << name << " - " << author << " (" << time / 60 << ", " << time % 60 << ") " << genre << instrument << endl;
}
void Song::OutP() {
	cout << name << " - " << author << " (" << time / 60 << ", " << time % 60 << ") " << genre << textaughtor << endl;
}
// Вывод меню и вызов других методов
void PlayList::ConsoleMenu() {
	cout << "Выберите действие:\n1 - подсчитать продолжительность плейлиста\n2 - отсортировать плейлист по стилю\n3 - найти музыку по заданному диапазону\nInput:\t";
	int variant;
	cin >> variant;
	switch (variant) {
	case 2:
		Sort();
		break;
	case 3:
		cout << "Введите диапазон в минутах и секундах\n";
		int tm1, ts1, tm2, ts2;
		cin >> tm1 >> ts1 >> tm2 >> ts2;
		Search(tm1, ts1, tm2, ts2);
		break;
	default:
		Calc();
		break;
	}
}
// Подсчитывание продолжительности плейлиста
void PlayList::Calc() {
	int sum = 0;
	for (int i = 0; i < SizeP; i++) {
		sum += pl[i]->getTime();
	}
	cout << "Продолжительность плейлиста: " << sum / 60 << ":" << sum % 60 << endl;
}
// Поиск треков по продолжительности
void PlayList::Search(int tm1, int ts1, int tm2, int ts2) {
	for (int i = 0; i < SizeP; i++) {
		// Если продолжительность трека находиться в границах, то выводим его
		if (pl[i]->getTime() >= tm1 * 60 + ts1&&pl[i]->getTime() <= tm2 * 60 + ts2) {
			pl[i]->OutP();
		}
	}
}
// Сортировка по жанру
/*
1
Трек1 Автор1 2 30 2 пианино
1
Трек2 Автор2 3 15 1 гитара
1
Трек3 Автор3 1 55 2 скрипка
1
@@@
1
*/
void PlayList::Sort() {
	// Функция из <algorithm> сортирует плейлист по жанру
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
	// Вывод отсортированного плейлиста
	for (int i = 0; i < SizeP; i++) {
		pl[i]->OutP();
		cout << endl;
	}
}
