#include "Header.h"

int main()
{
    int shm;
    char* addr;
    sem_t* semaphore;

    if ((shm = shm_open(SHARED_MEMORY_OBJECT_NAME, O_RDWR | O_CREAT, 0666)) == -1) {
        cout << "shm_open error" << endl;
        return -1;
    }


    if ((semaphore = sem_open(SEMAPHORE_NAME, O_CREAT, 0660, 1)) == SEM_FAILED) {
        cout << "sem_open error" << endl;
        return -1;
    }


    if (ftruncate(shm, SHARED_MEMORY_OBJECT_SIZE + 1) == -1) {
        cout << "fruncate error" << endl;
        return -1;
    }

    addr = (char*)mmap(0, SHARED_MEMORY_OBJECT_SIZE + 1, PROT_READ | PROT_WRITE, MAP_SHARED, shm, 0);

    if (addr == (char*)-1)
    {
        cout << "mmap error" << endl;
        return -1;
    }

    string input;
    char buf[200];

    while (true) {
        sem_wait(semaphore);
        cout << "input your message(input stop,if you want to finish):" << endl;
        getline(cin, input);
        memcpy(addr, input.c_str(), SHARED_MEMORY_OBJECT_SIZE);

        if (addr[0] == 's' && addr[1] == 't' && addr[2] == 'o' && addr[3] == 'p')
        {
            cout << "you are finished" << endl;
            break;
        }

        sem_post(semaphore);

        sleep(2);

        sem_wait(semaphore);
        memcpy(buf, addr, SHARED_MEMORY_OBJECT_SIZE);
        if (addr[0] == 's' && addr[1] == 't' && addr[2] == 'o' && addr[3] == 'p')
        {
            cout << "the client is finished" << endl;
            break;
        }

        for (int i = 0; i < (sizeof(addr) / 8); i++)
            if (addr[i] == 'Ч')
                addr[i] = '4';

        cout << "Client: ";
        cout << addr << endl;
        sem_post(semaphore);
    }

    sem_post(semaphore);
    munmap(addr, SHARED_MEMORY_OBJECT_SIZE);

    if (shm_unlink(SHARED_MEMORY_OBJECT_NAME) != 0)
    {
        cout << "shm_unlink error" << endl;
        return -1;
    }
    sem_unlink(SEMAPHORE_NAME);
    sem_close(semaphore);
    return 0;
}