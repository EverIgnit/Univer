#include<Windows.h>
#pragma comment(lib, "SPLab10_3.lib")

extern "C" __declspec(dllimport) void function();

int main()
{
	function();
	system("pause");
	return 0;
}