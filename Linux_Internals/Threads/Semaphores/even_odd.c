/**
 * single function
 * two threads
 * one thread prints even and other prints odd numbers
 * semaphore is being used to do that
*/
#include <stdio.h>

#include <pthread.h>
#include <semaphore.h>


pthread_mutex_t mutex;
pthread_cond_t condodd, condeven;
int num = 0;

sem_t even, odd;
int i=0;

void * evenOdd(void *type) {
    int val = *(int*)type;
    
    // printf("%d\n", val);
    
    while (i++ < 100) {
        if (val == 1) {
            sem_wait(&odd);
            printf("odd -> %d\n", num++);
            sem_post(&even);
        }
        else {
            sem_wait(&even);
            printf("even -> %d\n", num++);
            sem_post(&odd);
        }
    }
    
    
}

int main() {
    
    pthread_t t1, t2;
    sem_init(&odd, 0, 0);
    sem_init(&even, 0, 1);
    
    
    int val = 0;    // means odd
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condodd, NULL);
    
    pthread_cond_init(&condeven, NULL);
    pthread_create(&t1, NULL, evenOdd, &val);
    
    int val1 = 1;   // means even
    pthread_create(&t2, NULL, evenOdd, &val1);
    
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condodd);
    pthread_cond_destroy(&condeven);
    
}