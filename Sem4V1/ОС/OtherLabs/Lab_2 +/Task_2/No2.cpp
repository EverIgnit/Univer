#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{

	pid_t r;

	r = fork();
	if(r==0){
		execve("2_Task_Test.out", NULL, NULL);
	}

	return 0;
}
