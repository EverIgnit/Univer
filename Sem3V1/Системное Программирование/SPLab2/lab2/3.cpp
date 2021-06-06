/*
#undef UNICODE
#undef _INICODE
*/
#include <iostream>
#include <windows.h>

using namespace std;

int main() {

	ShellExecute (NULL, "open", "README.txt", NULL, "c:\\", SW_SHOWNORMAL);

	system("pause");
	return 0;
}