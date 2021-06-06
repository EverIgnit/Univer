//may not work on the first run
//if thats the case, remake with make file
#include<pthread.h>
#include<iostream>
#include <stdlib.h> 
#include <time.h>

//structure to be passed to thread
typedef struct DATA {
	DATA(int* array, int startIndex, int endIndex, int* resAccumulator, int thread_num) :
		Array(array), startIndex(startIndex), endIndex(endIndex), resAccumulator(resAccumulator), thread_num(thread_num)
	{}
	int* Array = NULL;
	int startIndex;
	int endIndex;
	int* resAccumulator;
    int thread_num;
} DATA;

//thread function
void* array_worker(void* arg){
    auto threadParams = (DATA*)arg;
	unsigned partSum = 0;
    int maxs = threadParams->Array[0];
	for (int i = threadParams->startIndex; i < threadParams->endIndex; i++) {
		if (threadParams->Array[i] > maxs) 
            maxs = threadParams->Array[i]; 
	}
    // std::cout <<"thread no" << threadParams->thread_num << ": ";
    // std::cout << "start index: " << threadParams->startIndex << "   end index: "<< threadParams->endIndex << "\n";
    threadParams->resAccumulator[threadParams->thread_num] = maxs;
	delete threadParams;
	return 0;
}


int main()
{    
    unsigned rows, columns, thread_num; 
    
    std::cout << "Array size (Rows):";
    std::cin >> rows;
    std::cout << "Array size (Columns):";
    std::cin >> columns;
    std::cout << "Number of threads:";
    std::cin >> thread_num;
    int array_size = rows*columns;

    //input check
    if((array_size <= 0) || (thread_num <= 0) || (array_size < thread_num) || (thread_num > 1000)){
        std::cerr << "Invalid input (one of)" << std::endl;
		system("pause");
		return 1;
    }
    //thread array
    pthread_t threads[thread_num+1];

    //array to be passed to the thread function
    int* result = new int;
	*result = 0;

    //1d array is sufficient, no need for 2d
    int* array = new int[rows*columns];


    srand(time(0)); //random seed
    for (int i = 0; i < array_size; i++){
		array[i] = rand() % 1000;
    }

    //array output
    std::cout << "\nArray:\n";
    for(int i = 0; i < rows*columns; i++){
        std::cout << array[i] << " ";
        if((i+1) % columns == 0)
            std::cout << "\n";
    }

    //sometimes division results in remainders, that need to be processed later 
    int threadArrayPartSize = array_size / thread_num;
	int lastArrayPartSize = array_size % thread_num;
    bool await_one_more = lastArrayPartSize != 0;

    // creating thread_num threads 
    for (unsigned i = 0; i < thread_num; i++){
        auto newThreadParams = new DATA(array, i * threadArrayPartSize, threadArrayPartSize * (i+1), result, i);
        pthread_create(&threads[i], NULL, array_worker, (void*)newThreadParams);
    }

    //if remainder != 0, one more thread is created
    if (await_one_more == true)
	{
		auto lastThreadParams = new DATA(array, thread_num * threadArrayPartSize, lastArrayPartSize, result, thread_num);
		pthread_create(&threads[thread_num], NULL, array_worker, (void*)lastThreadParams);
	}
    int final_join = await_one_more ? thread_num : thread_num + 1;

    // joining thread_num threads i.e. waiting for completion 
    for (unsigned i = 0; i < final_join; i++) 
        pthread_join(threads[i], NULL); 

    // std::cout << "result size:" << sizeof(result) <<"\nint size:" <<sizeof(int) <<"\n";
    
    //main thread is alos a thread, so calculating max here is justified
    int max = result[0];
    for(int i = 0; i < final_join-1; i++){
        std::cout << "Max[" << i << "] = " << result[i] << " ";
        if(result[i]>max)
            max = result[i];
    }

    //output
    std::cout <<"\nMax:" << max;
    std::cout << "\n";

    delete array;
    delete result;
    return 0;
}