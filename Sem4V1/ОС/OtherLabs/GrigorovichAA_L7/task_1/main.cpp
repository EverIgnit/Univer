#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <locale>
#include <string.h>

// Enter FileName here
#define name "file.txt"

int main(int argc, char const *argv[])
{
	SetConsoleOutput(1251);
	SetConsoleOutputCP(1251);

	// Open file
	int fd = open(name, O_RDWR);
	if (fd == -1) {
		perror("Failed to open file: ");
		return -1;
	}

	void *addr;
	off_t offset;
	// Get memory prganisation data
	size_t length = getpagesize();
	printf("%zu bytes\n", length);

	char *region = (char *)mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	close(fd);
	// Check mapping not to fail
	if (region == MAP_FAILED) {
		perror("mmap");
		return -1;
	}
	
	printf("%s\n", region);
	
	printf("Input key = 14: ");
	int key = 0;
	scanf("%d", &key);

	printf("\nText:\n");
	for (int i = 0; i<strlen(region); i++) {
		int bayt = int(region[i]) ^ key;
		printf("%c", char(bayt));
		region[i] = char(bayt);
	}
	printf("\n");
	// Free memory
	munmap(NULL, getpagesize());
	return 0;
}
