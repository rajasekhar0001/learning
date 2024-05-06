/**
 * Semaphore (Using semaphore as a mutex)
 * But Mutex can't be used as a semaphore as it maintains the count and multiple threads can apply
   wait or post calls on semaphore
   in case of mutex, thread which acquired mutex has to release until other threads can't acquire or use
   
 * It is one of the way to avoid race condition while multiple threads trying to access
   shared resource or critical section
 * sem_wait(&sem) -> if we want to use some shared resource
                     if sem value is 0, it will block calling thread until sem value > 0
                     if it is non zero decrements it
 * sem_post(&sem) -> if any thread or process done with resource, sem is incremented by 1 
                     to indicate resources availability to other threads or processes
 */
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

sem_t sem;

int count;
void *thread_function(void* data) {

    while (1) {
        sem_wait(&sem);
        count = 0;
        count += 5;
        count += 10;
        printf("%d\n", count);
        sem_post(&sem);
    }

}


int main() {

    sem_init(&sem, 0, 1);   // Semaphore is initialised with 1
    // It is being used as a binary semaphore here

    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, thread_function, NULL);
    pthread_create(&tid2, NULL, thread_function, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    sem_destroy(&sem);

    printf("Completed threads execution\n");

}