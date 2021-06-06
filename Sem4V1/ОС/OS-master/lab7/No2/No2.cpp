#include<iostream>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<string>


// char* generateKey(char base[], int base_len, int enc_length){
// 	char key[enc_length];
// 	for(int i = 0; i < enc_length; i++){
// 		key[i] = base[i]
// 	}
// 	return key;
// }

int main(){
    std::cout << "Input cipher key:"; // it does what it says
	std::string key;
	char key_chr[80];
    std::cin.getline(key_chr, 80);
	key = key_chr;

    std::cout << "File name to be ciphered (same directory):";
    char file[80];
    std::cin.getline(file, 80);
    int fd;
    if((fd = open(file, O_RDWR, S_IRUSR)) == -1) { //open file for reading
        std::cout << "Error opening file: " << strerror(errno) << "\n";
        return 1;
    }

    struct stat statbuf;
    if(fstat(fd, &statbuf) != 0){ // get file status (needed for size later)
        std::cout << "Fstat error: " << strerror(errno) << "\n";
        return 2;
    }
	
	int size = statbuf.st_size; // needed right here
    void* file_ptr; // mapped memory pointer

    if((file_ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED){ //map the file
        std::cout << "Error mapping file: " << strerror(errno) << "\n";
		return 3;
    }

	char file_chr[size];
	memcpy(file_chr, file_ptr, size); //copy file to char array

	std::cout << "File contents\n" << file_chr;

	std::cout << "\nEncryption start\n";
	for(unsigned i = 0; i < size;) { //encrypting
		unsigned j = 0;
		for(; j < key.length() && i < size;){
			file_chr[i] = file_chr[i] ^ key[j];
			j++;
			i++;
		}
	}

	std::cout << "Encryption end\n";

	std::cout << "Encryption result:\n" << file_chr << "\n";

	memcpy(file_ptr, file_chr, size); //copy enc text back to file


	std::cout << "Flushing to hard drive...\n";
	if(msync(file_ptr, size, MS_SYNC) != 0) { //flush to hard drive
		std::cout << "Error flushing: " << strerror(errno) << "\n";
		return 9;
	} 

    // std::cout << "File size:" << statbuf.st_size << "\n";

	//cleanup
	if(munmap(file_ptr, size) != 0){
		std::cout << "Error unmapping file: " << strerror(errno) << "\n";
		return 4;
	}

    if(close(fd) != 0){ //close file
        std::cout << "Error closing file: " << strerror(errno) << "\n";
		return 5;
	}
    return 0;
}