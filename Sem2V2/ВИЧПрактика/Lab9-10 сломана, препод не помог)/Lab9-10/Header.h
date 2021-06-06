// Белькевич Глеб Лаб 9, 10
#pragma once
#include <string>
#include <vector>
using namespace std;
// Абстрактный класс с полями время проигрывания, название и исполнитель трека
class Music {
	// Для наследования
protected:
	// Время в минутах и секундах как в одной переменной
	int time;
	// Название
	string name;
	// исполнитель
	string author;
	// Жанр
	int genre;
public:
	// Вввод/Вывод
	virtual void InP() = 0;
	virtual void OutP() = 0;
	// Геттеры
	int getTime();
	string getName();
	int getGenre();
};
// Класс с полем, хранящим музыкальный инструмент мелодии
class Melody : public Music {
	string instrument;
public:
	void InP();
	void OutP();
};
// Класс с полем, содержащим жанр песни
class Song : public Music {
	string textaughtor;
public:
	void InP();
	void OutP();	
};
// Контейнерный класс, содержащий набор треков с требуемыми методами
class PlayList {
	// Контейнер треков
	Music **pl;
	// Размер контейнера
	int SizeP;
public:
	// Конструктор
	PlayList();
	// Поиск по продолжительности
	void Search(int, int, int, int);
	// Сортировка по жанрам
	void Sort();
	// Подсчёт продолжительности
	void Calc();
	// Консольное меню выбора функции
	void ConsoleMenu();
};
