#include <stdio.h>
#include <pthread.h>

void * function (void * arg)
{
    fprintf (stderr, "Some text \n");
    while (1) {
        getchar();
        printf("Exit");
        pthread_exit(NULL);
    }
    return 0;
}

int main (void)
{ 
    pthread_t th;
    for(int i=0; i<7; i++){
        if (pthread_create (&th, NULL, &function, NULL) != 0) {
	    fprintf(stderr, "Error\n");
  	    return 1;
        }
    }
    for(int i=0;i<5;i++){
        fprintf(stderr, "Another text\n");
    }
   getchar();
   printf("Exit");
   pthread_exit(NULL);
}
