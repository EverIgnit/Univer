#include<sys/mman.h>
#include<iostream>
#include<unistd.h> 
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>        /* For mode constants */
#include<fcntl.h>           /* For O_* constants */
#include<string.h>
#include<errno.h>
#include<semaphore.h>

#define sem_name "/no1_sem"

bool check_exit(char array[256]){
	return array[0]=='e' && array[1]=='x' && array[2]=='i' && array[3]=='t';
}

int main(){
	int fd, msg_size = 256;
    //get shared memory
    const char* name = "/msg-transfers";
	fd = shm_open(name, O_RDWR, 0666); 
	if(fd == -1){
		std::cout << "error opening shared memory:" << errno <<"\n";
		return 2;
	}	
	sem_t *sem;
	if((sem = sem_open(sem_name, 0)) == SEM_FAILED) {
		std::cout << "failed to open semaphore\n";
		return 7;
	}

	void* mem_ptr = mmap(0, msg_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	char message[256];
	bool e = true;
	std::cout << "------------------------------------\n";
    while(e){
		//send
		std::cout << "You:";
		std::cin.getline(message, msg_size);
		memcpy(mem_ptr, message, msg_size);
		if(check_exit(message)){
			std::cout << "disconnecting\n";			
			break;
		}
		sem_post(sem);
		sleep(0);
		std::cout << "Server:";

		sem_wait(sem);
		//receive
		sleep(0);

		memcpy(message, mem_ptr, msg_size);
		std::cout << message << "\n";
		if(check_exit(message)){
			e = false;
			std::cout << "Server disconnected\n";
		}
	}
    sem_post(sem);
	  //cleanup
  	munmap(mem_ptr, msg_size);
	sem_close(sem);
	return 0;
}