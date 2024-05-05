/**
 * Mutex 
 * WHat happens if we wont use Mutex, when we are using shared variables ?
 * 
 * race condition: If multiple threads are trying to access the shared resource it may lead to data corruption
 * 
 * To avoid race condition, we use mutex
 * 
 * 
 * 
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int count;
void *thread_function(void *data) {
    while (1) {
        count = 0;
        count += 5;
        count += 20;
        printf("%d\n", count);
    }
}


int main() {

    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, thread_function, NULL);
    pthread_create(&tid2, NULL, thread_function, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

}