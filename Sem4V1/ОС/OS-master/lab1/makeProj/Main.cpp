#include<iostream>
#include "Fixer.h"
int main() {
	Fixer fixer = Fixer(-22);
	std::cout << "Fix \'em up!\n";
	std::cout << "-22 turns into " << fixer.fix() <<"!\n";
}