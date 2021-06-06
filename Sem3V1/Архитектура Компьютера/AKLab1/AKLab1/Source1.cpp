#include "Header.h"
#include <iostream>
#include <windows.h>
using namespace std;
// Bot
Bot::Bot() {
	direction = 1, x = 0, y = 0;
}
int Bot::getdirection() {
	return direction;
}
int Bot::getx() {
	return x;
}
int Bot::gety() {
	return y;
};
void Bot::setdirection(int a) {
	direction = a;
}
void Bot::setx(int a) {
	x = a;
}
void Bot::sety(int a) {
	y = a;
}

// Logic
void Logic::Move(Bot& Arnold, Data& data) {
	if (Arnold.getdirection() < 1 || Arnold.getdirection() > 4) {
		cout << "ERROR!! CODE: DIRECTION\n";
		return;
	}
	switch (Arnold.getdirection()) {
	case 3:
		if (CanMoveToCell(Arnold.getx() - 1, Arnold.gety(), data))
			Arnold.setx(Arnold.getx()-1);
		break;
	case 2:
		if (CanMoveToCell(Arnold.getx(), Arnold.gety()+1, data))
			Arnold.sety(Arnold.gety() + 1);
		break;
	case 1:
		if (CanMoveToCell(Arnold.getx() + 1, Arnold.gety(), data))
			Arnold.setx(Arnold.getx() + 1);
		break;
	case 4:
		if (CanMoveToCell(Arnold.getx(), Arnold.gety() - 1, data))
			Arnold.sety(Arnold.gety() - 1);
		break;
	}
}
bool Logic::CanMoveToCell(int a, int b, Data& data) {
	if (a<0 || a>9 || b<0 || b>9) {
		return false;
	}
	if (data.getcell(a, b) == 1)
		return false;
	return true;
}
void Logic::TurnRight(Bot& Arnold) {
	Arnold.setdirection(Arnold.getdirection()-1);
	if (Arnold.getdirection() == 0) {
		Arnold.setdirection(4);
	}
}
void Logic::TurnLeft(Bot& Arnold) {
	Arnold.setdirection(Arnold.getdirection() + 1);
	if (Arnold.getdirection() == 5) {
		Arnold.setdirection(1);
	}
}
void Logic::PickMarker(Bot& Arnold, Data& data) {
	if (data.getcell(Arnold.getx(),Arnold.gety()) == 2) {
		data.setcell(Arnold.getx(), Arnold.gety(), 0);
		data.setstorage(data.getstorage() + 1);
	}
}
void Logic::PlaceMarker(Bot& Arnold, Data& data) {
	if (data.getcell(Arnold.getx(), Arnold.gety()) == 0 && data.getstorage() > 0) {
		data.setcell(Arnold.getx(), Arnold.gety(), 2);
		data.setstorage(data.getstorage()-1);
	}
	CheckForWin(data);
}
void Logic::CheckForWin(Data &data) {
	if (data.getcell(4, 4)=='O'&&data.getcell(4, 5) == 'O'&&data.getcell(4, 6) == 'O'&&data.getcell(4, 7) == 'O'&&data.getcell(5, 4) == 'O'&&data.getcell(6, 4) == 'O'&&data.getcell(7, 4) == 'O'&&data.getcell(7, 5) == 'O'&&data.getcell(7, 6) == 'O'&&data.getcell(5, 7) == 'O'&&data.getcell(6, 7) == 'O'&&data.getcell(5, 7) == 'O'&&data.getcell(6, 7) == 'O'&&data.getcell(6, 6) == 'O'&&data.getcell(7, 7) == 'O') {
		cout<< "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\t\tYOU WIN!!!!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
	}
}

// Storage
Data::Data() {
	storage = 0;
	int field1[10][10] = {
		{ 0, 0, 0, 1, 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 2, 2, 1, 0, 0, 0 },
		{ 0, 0, 2, 0, 0, 0, 0, 2, 0, 0 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 0, 2, 0, 0, 1, 1, 0, 0, 2, 0 },
		{ 0, 2, 0, 0, 1, 1, 0, 0, 2, 0 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 0, 0, 2, 0, 0, 0, 0, 2, 0, 0 },
		{ 0, 0, 0, 1, 2, 2, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 1, 0, 0, 0 }
	};
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			field[i][j] = field1[i][j];
		}
	}
}
int Data::getstorage() {
	return storage;
}
int Data::getcell(int i, int j) {
	return  field[i][j];
}
void Data::setstorage(int a) {
	storage = a;
}
void Data::setcell(int x, int y, int a) {
	field[x][y] = a;
}

// Controls
void Controls::Execute(Logic logic, int action, Bot& Arnold, Data& data) {
	if (action < 1 || action>6) {
		cout << "ERROR!! CODE: ACTION\n";
		return;
	}
	switch (action) {
	case 1:
		logic.Move(Arnold, data);
		break;
	case 2:
		logic.TurnRight(Arnold);
		break;
	case 3:
		logic.TurnLeft(Arnold);
		break;
	case 4:
		logic.PickMarker(Arnold, data);
		break;
	case 5:
		logic.PlaceMarker(Arnold, data);
		break;
	default:
		return;
		break;
	}
}

// OutP, InP
void InpOutp::ShowInfo(Bot& Arnold, Data& data) {
	// Вывод поля
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == Arnold.getx() && j == Arnold.gety()) {
				switch (Arnold.getdirection()) {
				case 1:
					cout << "V ";
					break;
				case 2:
					cout << "> ";
					break;
				case 3:
					cout << "^ ";
					break;
				case 4:
					cout << "< ";
					break;
				}
			}
			else {
				switch (data.getcell(i, j)) {
				case 0:
					cout << "  ";
					break;
				case 1:
					cout << "# ";
					break;
				case 2:
					if (Arnold.getx() != i || Arnold.gety() != j)
						cout << "O ";
					break;
				}
			}
		}
		cout << endl;
	}
	// Вывод меню
	cout << "\nStorage:\t" << data.getstorage() << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
	cout << "Choose an action:\n1 - Move\n2 - TurnRight\n3 - TurnLeft\n4 - PickMarker\n5 - PlaceMarker\n6 - EXIT\nInput: ";
}
bool InpOutp::InP(Logic logic, Bot& Arnold, Data& data) {
	int action;
	cin >> action;
	if (action == 6)
		return false;
	Controls ctrl;
	ctrl.Execute(logic, action, Arnold, data);
	return true;
}