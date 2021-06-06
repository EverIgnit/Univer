#pragma once
#include<sys/mman.h>
#include<unistd.h> 
#include<stdio.h>
#include<sys/stat.h>        
#include<fcntl.h>          
#include<string.h>
#include<sys/shm.h>
#include<semaphore.h>
#include<iostream>

#define SHARED_MEMORY_OBJECT_NAME "DATAMEMORY"
#define SHARED_MEMORY_OBJECT_SIZE 200
#define SEMAPHORE_NAME "/my_semaphore"

using namespace std;