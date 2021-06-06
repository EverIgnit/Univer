#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

int N=0;
int sizeMeat=0;
int piceMeat=0;

sem_t cook;
sem_t eat;

void* Eating(void* argc){
    while(true){
        sem_wait(&eat);

        if(sizeMeat==piceMeat){
            sem_wait(&cook);
        }

        sizeMeat--;

        if (sizeMeat <= 0) {
		sem_post(&cook);
		sleep(1);
		}

        cout << "Мясо осталось "<< sizeMeat << endl;

        sem_post(&eat);

		sleep(7);
	}

}
void* Cooking(void* argc) {
	while(true) {

		sem_wait(&cook);
		
		sizeMeat = piceMeat;
		cout << piceMeat<< "Level up\n";

        sem_post(&cook);

        if (piceMeat == 1) {
			sleep(7);
		} else {
			sleep(7);
		}
    }
	
}

int main(){

    pthread_t cooking;
    cout<<"Введите количество канибаллов"<<endl;
    cin>>N;
     
    if(N<1){
        cout<<"Маловато ввели"<<endl;
        return 0;
    }

    cout<<"Сколько кусков мяса вмещает горшок?"<<endl;
    cin>>piceMeat; 
    sizeMeat=piceMeat;
    if(piceMeat<1){
        cout<<"Интерено, где взяли такой маленький горшок..."<<endl;
        return 0;
    }
    
    sem_init(&cook,0,1);
    sem_init(&eat,0,1);

    pthread_t *eating =new pthread_t[N];

    for(int i=0;i<N;i++)
    {
        if(pthread_create(&eating[i],NULL,Eating,NULL)!=0)
        {
            cout<<"Не удалось создать поток"<<endl;
            return 0;;
        }
    }
    
    if(pthread_create(&cooking,NULL,Cooking,NULL)!=0)
    {
        cout<<"Не удалось создать поток"<<endl;
        return 0;
    }

    for (int i = 0; i<N; i++) {
		pthread_join(eating[i], NULL);
	}

    sem_destroy(&eat);
    sem_destroy(&cook);
    return 0;

}
