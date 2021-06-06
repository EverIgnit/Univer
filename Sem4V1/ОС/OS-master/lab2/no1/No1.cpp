#include <iostream> 
#include <unistd.h> 
#include <string>

int main() 
{ 
    int pid; 
    pid = fork(); 
    if (pid == 0) 
    { 
        std::cout << "Parent Process id (PID) : " 
             << getpid() << std::endl; 
        std::cout << "\nChild Process with parent id (PPID) : " 
             << getppid() << "\n"; 
    }
	std::string line;
	std::cout << "Press enter to exit";
	std::getline(std::cin, line);
    return 0; 
}
