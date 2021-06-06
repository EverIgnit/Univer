#undef UNICODE
#undef _INICODE

#include <iostream>
#include <windows.h>

using namespace std;

int main() {

	ShellExecute(NULL, "open", "iexplore.exe", NULL, "C:\\TEMP", SW_SHOWNORMAL);

	system("pause");
	return 0;
}