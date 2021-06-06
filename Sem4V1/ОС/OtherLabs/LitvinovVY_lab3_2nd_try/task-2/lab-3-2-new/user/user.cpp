#include <iostream>
#include <Windows.h>
#include <cstring>
using namespace std;
#define BUF_SIZE 500
TCHAR nameOfMapping[] = TEXT("Mapping");
TCHAR nameOfEvent[] = TEXT("Event");
string str;//message
int main() {
    setlocale(0, "");

    HANDLE hMapping = OpenFileMapping(
        FILE_MAP_ALL_ACCESS,   // ������ � ������/������
        FALSE,                 // ��� �� �����������
        nameOfMapping          // ��� "������������� " ������� 
    );               
    if (hMapping == NULL)
    {
        cout << "������ ��������� ����������� Mapping" << GetLastError() << endl;
        return 0;
    }
    else cout << "���������� Mapping �������" << hMapping << endl;

    HANDLE hEvent = OpenEvent(EVENT_MODIFY_STATE, FALSE, nameOfEvent);

    if (hEvent == NULL)
    {
        cout << "������ ��������� ����������� Event" << GetLastError() << endl;
        return 0;
    }
    else cout << "���������� Event �������" << hEvent << endl;

    char* itog = (char*)MapViewOfFile(hMapping, FILE_MAP_WRITE, 0, 0, 0);

    cout << "������� ���������" << endl;    cin >> str;
    memcpy(itog, str.c_str(), str.size());
    SetEvent(hEvent);
    //close
    UnmapViewOfFile(itog);
    CloseHandle(hMapping);
    CloseHandle(hEvent);
    system("pause");
    return 0;
}