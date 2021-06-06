#pragma once
class Bot {
	int direction;
	int x;
	int y;
public:
	Bot();
	int getdirection();
	void setdirection(int);
	int getx();
	int gety();
	void setx(int);
	void sety(int);
};

class Data {
	int storage;
	int field[10][10];
public:
	Data();
	int getstorage();
	void setstorage(int);
	int getcell(int, int);
	void setcell(int, int, int);
};

class Logic {
public:
	void Move(Bot&, Data&);
	bool CanMoveToCell(int, int, Data&);
	void TurnRight(Bot&);
	void TurnLeft(Bot&);
	void PickMarker(Bot&, Data&);
	void PlaceMarker(Bot&, Data&);
	void CheckForWin(Data&);
};

class Controls {
public:
	void Execute(Logic, int, Bot&, Data&);
};

class InpOutp {
public:
	void ShowInfo(Bot&, Data&);
	bool InP(Logic, Bot&, Data&);
};