#include <iostream> 
#include <unistd.h> 
#include <string>

int main(int argc, char const *argv[]) 
{ 
    int pid; 
    pid = fork(); 
    if (pid == 0) 
    { 
        std::cout << "PID : " << getpid() << std::endl; 
        std::cout << "PPID : " << getppid() << std::endl; 
    }
    return 0; 
}
