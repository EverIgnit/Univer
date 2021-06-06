#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <iconv.h>

using namespace std;

int main() {
    int f_des = open("in.txt", O_RDWR);
    if (f_des == -1) {
        cout << "File opening err." << endl;
        return 0;
    }
    else cout << "Opening successfull." << endl;

    struct stat statbuf;

    if (fstat(f_des, &statbuf) != 0) {
        cout << "Fstat error: " << strerror(errno) << "\n";
        return 0;
    }

    int size = statbuf.st_size;

    void* str = mmap(NULL, size, PROT_WRITE, MAP_SHARED, f_des, 0);
    char* file_chr;

    memcpy(file_chr, str, size);

    cout << file_chr << endl;
    char[20] scifr;
    cout << "Enter a string\n->\t";
    cin >> scifr;
    /*
    iconv_t d;
    size_t f, t;
    f = t = size;
    d = iconv_open();//из какой в какую кодировку
    iconv(d, &file_chr, &f, &file_chr, &t);
    */file_chr = file_chr xor scift;
    int fd = open("output.txt", O_RDWR);
    write(fd, file_chr, size);
    return 0;

}
