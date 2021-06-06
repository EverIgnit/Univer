#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);

	int PID;
	cout << "������� PID ��������:  " << endl;
	cin >> PID;

	HANDLE pr = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);
	cout << "������� ��� ���������� ��������, �� ������� ������ ��������: 1 - ���� ��������, 2- �������, 3 - ���� ��������, 4 - �������\n";
	int code;
	cin >> code;
	switch (code) {
	case 1:
		if (SetPriorityClass(pr, BELOW_NORMAL_PRIORITY_CLASS) == TRUE) {
			cout << "��������� �������� ������" << endl;
		}
		else cout << "��������� �������� �������� �� �������" << endl;
		break;
	case 2:
		if (SetPriorityClass(pr, NORMAL_PRIORITY_CLASS) == TRUE) {
			cout << "��������� �������� ������" << endl;
		}
		else cout << "��������� �������� �������� �� �������" << endl;
		break;
	case 3:
		if (SetPriorityClass(pr, ABOVE_NORMAL_PRIORITY_CLASS) == TRUE) {
			cout << "��������� �������� ������" << endl;
		}
		else cout << "��������� �������� �������� �� �������" << endl;
		break;
	default:
		if (SetPriorityClass(pr, HIGH_PRIORITY_CLASS) == TRUE) {
			cout << "��������� �������� ������" << endl;
		}
		else cout << "��������� �������� �������� �� �������" << endl;
		break;
	}
	

	system("pause");
	return 0;
}