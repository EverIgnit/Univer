#include <sys/types.h>
#include <unistd.h>
#include <iostream>
//#include <iostream>

int main(int argc, char *argv[])
{
	pid_t pid;
	if ((pid = fork()) == -1)
		std::cout << "fork error";
	else if (pid == 0){ 
		if(argc>1)
			execl("/bin/ls", "ls", "-1", argv[argc-1], NULL);
		else
			execl("/bin/ls", "ls", "-1", NULL);		
        	std::cout<<"Return not expected. Must be an execl() error\n";
    	}	
	return 0;
}

