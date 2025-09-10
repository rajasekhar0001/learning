#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#define MAX 100

sem_t odd, even;
int val = 0;

void* printEven(void* data) {
    while (val < MAX) {
        sem_wait(&even);
        printf("%d ", val++);
        fflush(stdout);
        // sleep(1);
        sem_post(&odd);
    }
}

void *printOdd(void* d) {
    while (val < MAX) {
        sem_wait(&odd);
        printf("%d ", val++);
        fflush(stdout);
        // sleep(1);
        sem_post(&even);
    }
}

int main() {

    pthread_t t1;
    pthread_t t2;
    
    sem_init(&odd, 0, 0);
    sem_init(&even, 0, 1);
    pthread_create(&t1, NULL, printEven, NULL);
    pthread_create(&t2, NULL, printOdd, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&odd);
    sem_destroy(&even);
}