#include<stdio.h>
int main()
{
printf("PID: %d\n ",getpid());
printf("PPID: %d\n ",getppid());
sleep(300);
return 0;
}
