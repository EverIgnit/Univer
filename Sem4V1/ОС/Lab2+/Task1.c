#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("PID: %d\nPPID: %d\n ",getpid(), getppid());
	return 0;
}
