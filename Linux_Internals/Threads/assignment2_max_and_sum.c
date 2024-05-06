/*
WAP to sum and maximum of a given array using multiple threads. Synchronize threads 
using mutex.
 Pre-requisites:- 
• Knowledge about multi-thread process, How to read and understand ‘man pages’.
• Good knowledge about pthread library functions.
• Thread synchronization (mutex and semaphores).
Objective: -
• To understand need and implementation of thread synchronization.
Requirements: -
1. Create an array[N] (min size 500) with 1 N values and two global variables →
global_sum & global_max.
2. Create multiple threads to find sum of array and maximum value in array.
3. Threads will share array equally among them. Means each thread will access 
different part of array at same time. 
4. Create at-least 5 threads. Create and join threads using separate loops.
5. Each thread will update global_sum and global_max.
6. Since we are accessing global variable from threads, do proper synchronization 
using mutex.
Sample execution: -
1. ./sum_max
max = 100
Sum = 1020
*/

#include <stdio.h>
#include <pthread.h>

int global_max;
long global_sum;

typedef struct {
    int n;
    int arr[1000];
    int start;
    int end;
} array;

pthread_mutex_t mutex;

void *find_max_and_sum(void *data) {
    array *a = (array*) data;

    

    if (global_max == 0) {
        global_max = a->arr[a->start];
        // m = a->arr[0];
    }
    for (int i=a->start;i < a->end;i++) {
        // Mutex lock
        pthread_mutex_lock(&mutex);
        if (global_max < a->arr[i]) {
            global_max = a->arr[i];
            // m = a->arr[i];
        }
        global_sum += a->arr[i];
        pthread_mutex_unlock(&mutex);
    }
    // printf("Max : %d       Sum of aarray: %ld\n", global_max, global_sum);
}


int main() {
    pthread_t tid1, tid2, tid3, tid4, tid5; 

    pthread_mutex_init(&mutex, NULL);
    int size = 10;
    array a = {size, {100, 6, 7, 8, 9, 1, 11, 32, 77}};
    array a1 = a;
    array a2 = a;
    array a3 = a;
    array a4 = a;
    array a5 = a;
    array a6 = a;
    // printf("%p    %p\n", &a, &a1);

    a.start = 0;
    a.end = size/2;
    pthread_create(&tid1, NULL, find_max_and_sum, &a);

    a1.start = a.end;
    a1.end = a.end + (size/2);
    pthread_create(&tid2, NULL, find_max_and_sum, &a1);

    a2.start = a1.end;
    a2.end = a1.end + (size/2);
    pthread_create(&tid3, NULL, find_max_and_sum, &a2);

    a3.start = a2.end;
    a3.end = a2.end + (size/2);
    pthread_create(&tid4, NULL, find_max_and_sum, &a3);

    a4.start = a3.end;
    a4.end = size;
    pthread_create(&tid5, NULL, find_max_and_sum, &a4);


    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    pthread_join(tid4, NULL);
    pthread_join(tid5, NULL);

    pthread_mutex_destroy(&mutex);

    printf("Max : %d\nSum of aarray: %ld\n", global_max, global_sum);
}