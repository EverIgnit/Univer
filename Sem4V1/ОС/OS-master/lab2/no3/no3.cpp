#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <errno.h>
#include <signal.h>

int main(int argc, char *argv[])
{
	std::cout << "Enter victim\'s PID: ";
	pid_t pid;
	std::cin >> pid;

	if(kill(pid, 9) != 0){
		std::cout <<"This ain\'t it chief. This shouldn\'t happend";
		return -1;
	}
	else
		std::cout << "Successful process termination\n";
	return 0;
}

