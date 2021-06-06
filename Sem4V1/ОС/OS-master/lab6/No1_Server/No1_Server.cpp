#include<sys/mman.h>
#include<iostream>
#include<unistd.h> 
#include<stdio.h>
#include<sys/stat.h>        /* For mode constants */
#include<fcntl.h>           /* For O_* constants */
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<semaphore.h>

#define sem_name "/no1_sem"

//TODO: fix this mess

bool check_exit(char array[256]){
	return array[0]=='e' && array[1]=='x' && array[2]=='i' && array[3]=='t';
}

int main(){
	int fd, SIZE = 256;
  	const char* name = "/msg-transfers";	  
	fd = shm_open(name, O_RDWR | O_CREAT, 0666); 
	if(fd == -1){
		std::cout << "error creating shared memory:" << errno <<"\n";
		return 2;
	}
	sem_t *sem ;
	if((sem= sem_open(sem_name, O_CREAT, 0660, 0)) == SEM_FAILED){
		std::cout << "failed to open semaphore\n";
		return 7;
	}
	ftruncate(fd, SIZE);
	void* mem_ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	
	bool e = true;
	char message[256];
	std::cout << "------------------------------------\n";

	std::cout << "Waiting for client...\n";
	
	
	// std::cout <<
    while(e){
		std::cout << "Client:";
		//RECV
		sem_wait(sem);
		memcpy(message, mem_ptr, SIZE);
		std::cout << message << "\n";
		if(check_exit(message))
		{
			e = false;
			std::cout << "client disconnected\n";
		}
		//SEND
		else {
			std::cout << "Server:";
			std::cin >> message;
			if(check_exit(message)){
				e = false;
				std::cout << "Disconnecting\n";
			}
			memcpy(mem_ptr, message, SIZE);
			sem_post(sem);
			sleep(0);
		}
		
	}
	
  	if(shm_unlink(name) != 0){
    	std::cout << "error closing shm:" << errno << "\n";
    	return 3;
  	}
	sem_unlink(sem_name);
	if(sem_close(sem) != 0){
		std::cout << "error closing semaphore\n";
	  	return 6;
	}
	return 0;
}