#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <iostream>

#define PIPE_SERVER "/tmp/no2_server"
#define PIPE_CLIENT "/tmp/no2_client"

bool check_exit(char array[256]){
	return array[0]=='e' && array[1]=='x' && array[2]=='i' && array[3]=='t';
}

int main(){
    int fd_server, fd_client; //for open()
    std::cout << "Pipe system\n";


	//server
    if(mkfifo(PIPE_SERVER, 0644) == 0) {
        std::cout << "Server pipe exists\n";
        // if((fd_server = open (PIPE_SERVER, O_RDONLY)) == -1)//SERVER LISTENS
        if((fd_server = open (PIPE_SERVER, O_RDONLY)) == -1)//SERVER LISTENS
        {
			// std::cout << "server pipe = " << PIPE_SERVER<<"\n";
            std::cout << "Error opening server pipe for reading:" << strerror(errno) <<"\n";
            return 1;
        } 
        bool e = true;
        int bytes_read;
        char buf [256];
		std::cout << "Waiting for client\n";
        while(e) {
            //get message
            memset(buf, '\0', sizeof (buf)); //empty
            if((bytes_read = read (fd_server, buf, sizeof (buf))) == -1){
                std::cout <<"Server error: read\n";
				return 4;
            }
            if(bytes_read == 0)
        	    continue; //nothing to be received


			if (bytes_read > 0) {
				std::cout << ">Client:" << buf << "\n";
				if(check_exit(buf)){
					std::cout << "Client disconnects\n";
					e = false;
					continue;
				}
				std::cout << ">Server:";
				std::cin >> buf;
				
        	    /* Send the result */
        		// if ((fd_client = open (PIPE_CLIENT, O_WRONLY)) == -1) {
        		if ((fd_client = open (PIPE_CLIENT, O_WRONLY)) == -1) {
        		    std::cout << "Server error: failed to open client pipe for writing\n";
					continue;
        	    }


        	    if (write (fd_client, buf, strlen (buf)) != strlen (buf)){
					std::cout << "Server error: failed to write all bytes to pipe\n";
				}

        	    if (close (fd_client) == -1){
					std::cout << "Server error: error closing client pipe\n";
				}
				//vibe check
				if(check_exit(buf)){
					std::cout << "Server disconnects\n";
					e = false;
					continue;
				}
        	}

        }
		//delete pipes
		remove(PIPE_SERVER);
		remove(PIPE_CLIENT);
		return 0;
    }

	//client
    else if(errno == EEXIST){
        std::cout << "Server pipe exists, creating client\n";
        if(mkfifo(PIPE_CLIENT, 0644) == -1) {
            std::cout << "Error creating client pipe\n";
            return 2;
        }
		std::cout << "Client pipe created\n";
		bool e = true;
        int bytes_read;
        char buf [256];
		while(e){
			//user input
			std::cout << ">Client:";
			std::cin >> buf;
			//send message
			// if ((fd_server = open (PIPE_SERVER, O_WRONLY)) == -1) {
			if ((fd_server = open (PIPE_SERVER, O_WRONLY)) == -1) {
            	std::cout << "Client error: server fifo\n";
            	break;
        	}

        	if (write (fd_server, buf, strlen (buf)) != strlen (buf)) {
            	std::cout << "Client error: write\n";
        		break;
	        }

    	    if (close (fd_server) == -1) {
        	    std::cout << "Cleint error: close\n";
            	break;
        	}

			//check exit
			if(check_exit(buf)){
				std::cout << "Client disconnects\n";
				e = false;
				continue;
			}
			

			// read the answer
        	// if ((fd_server = open (PIPE_CLIENT, O_RDONLY)) == -1)
        	if ((fd_server = open (PIPE_CLIENT, O_RDONLY)) == -1)
            	std::cout << "Client error: open read\n";

        	memset (buf, '\0', sizeof (buf)); //empty
        	if ((bytes_read = read (fd_server, buf, sizeof (buf))) == -1)
         	   std::cout << "Client error: read\n";

        	if (bytes_read > 0) {
        	    std::cout << ">Server:" << buf << "\n";
        	}

        	if (close (fd_server) == -1) {
        	    std::cout << "Client error: close server fifo";
        	    break;
			}
			//vibe check
			if(check_exit(buf)){
				std::cout << "Server disconnects\n";
				e = false;
				continue;
			}

		}
		std::cout << "Server disconnected\n";
		return 0;
    }
    else {
        std::cout << "Pipe creation error: " << strerror(errno) <<"\n";
        return 9;
    }
}