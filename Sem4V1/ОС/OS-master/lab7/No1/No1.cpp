#include<unistd.h>
#include<iostream>

int main(){
    std::cout << "Page size: " << sysconf(_SC_PAGE_SIZE) <<"\n";
    std::cout << "Number of pages of physical memory: " << sysconf(_SC_PHYS_PAGES) <<"\n";
    std::cout << "Available pages of physical memory: " << sysconf(_SC_AVPHYS_PAGES) <<"\n";
    std::cout << "Number of processors configured: " << sysconf(_SC_NPROCESSORS_CONF) <<"\n";
    std::cout << "Number of processors online: " << sysconf(_SC_NPROCESSORS_ONLN) <<"\n";

    return 0;
}