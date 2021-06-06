#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <signal.h>

using namespace std;

int main(int argc, char const *argv[])
{
	cout << "Enter pid for kill prosecc: ";
	pid_t pid;
	cin >> pid;

    if(kill(pid,0) == -1) {
    printf("pid error\n");
    return-1;
    }

	if (kill(pid, SIGBUS) == -1) {
		cout << "Error" << endl;
		return 1;
	}
	else
    cout << "Your process is killed!" << endl;
	return 0;
}
