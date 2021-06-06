#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
using namespace std;

int main(int argc, char const *argv[]){

	cout<< "Enter pid for stop prosecc:\n->\t";
	pid_t pid;
	cin>>pid;

	if(kill(pid, SIGABRT) != -0)
		cout<<"Something wrong."<< std::endl;
	return 0;
}
