#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <iostream>

using namespace std;

#define PIPE_SERVER "/Task2/no2_server"
#define PIPE_CLIENT "/Task2/no2_client"

int main(){
    int server, client; 

    if(mkfifo(PIPE_SERVER, 0644) == 0) {
        cout << "Server pipe\n";

        if((server = open (PIPE_SERVER, O_RDONLY)) == -1)
        {
            cout << "Error:" << strerror(errno) <<"\n";
            return 1;
        } 

        bool e = true;
        int bytes_read;
        char buf [256];
		cout << "Waiting for client\n";
        while(e) {
            memset(buf, '\0', sizeof (buf)); 
            if((bytes_read = read (server, buf, sizeof (buf))) == -1){
                cout <<"Error\n";
				return 4;
            }

            if(bytes_read == 0)
        	    continue; 

			if (bytes_read > 0) {
				cout << "Client:" << buf << "\n";
				if(buf[0]=='c' && buf[1]=='l' && buf[2]=='o' && buf[3]=='s'&& buf[4]=='e'){
					cout << "Client disconnects\n";
					e = false;
					continue;
				}
				cout << "Server:";
				cin >> buf;
				
        		if ((client = open (PIPE_CLIENT, O_WRONLY)) == -1) {
        		    cout << "Error\n";
					continue;
        	    }


        	    if (write (client, buf, strlen (buf)) != strlen (buf)){
					cout << "Error\n";
				}

        	    if (close (client) == -1){
					cout << "Error\n";
				}
				if(buf[0]=='c' && buf[1]=='l' && buf[2]=='o' && buf[3]=='s'&& buf[4]=='e'){
					cout << "Server disconnects\n";
					e = false;
					continue;
				}
        	}
        }

		remove(PIPE_SERVER);
		remove(PIPE_CLIENT);

		return 0;
    }

    else if(errno == EEXIST){
        cout << "Server exists, creating client\n";

        if(mkfifo(PIPE_CLIENT, 0644) == -1) {
            cout << "Error\n";
            return 2;
        }

		cout << "Client created\n";
		bool e = true;
        int bytes_read;
        char buf [256];

		while(e){
			cout << "Client:";
			cin >> buf;
			if ((server = open (PIPE_SERVER, O_WRONLY)) == -1) {
            	cout << "Error\n";
            	break;
        	}

        	if (write (server, buf, strlen (buf)) != strlen (buf)) {
            	cout << "Error\n";
        		break;
	        }

    	    if (close (server) == -1) {
        	    cout << "Error\n";
            	break;
        	}
			if(buf[0]=='c' && buf[1]=='l' && buf[2]=='o' && buf[3]=='s'&& buf[4]=='e'){
				cout << "Client disconnects\n";
				e = false;
				continue;
			}
				
        	if ((server = open (PIPE_CLIENT, O_RDONLY)) == -1)
            	cout << "Error\n";

        	memset (buf, '\0', sizeof (buf)); 
        	if ((bytes_read = read (server, buf, sizeof (buf))) == -1)
         	   cout << "Error\n";

        	if (bytes_read > 0) {
        	    cout << "Server:" << buf << "\n";
        	}

        	if (close (server) == -1) {
        	    cout << "Error";
        	    break;
			}
			if(buf[0]=='c' && buf[1]=='l' && buf[2]=='o' && buf[3]=='s'&& buf[4]=='e'){
				cout << "Server disconnects\n";
				e = false;
				continue;
			}

		}
		cout << "Server disconnected\n";
		return 0;
    }
    else {
        cout << "Pipe creation error: " << strerror(errno) <<"\n";
        return 9;
    }
}
