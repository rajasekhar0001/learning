/**
 * // When a same thread going to lock the thread twice or more, the calling thread will go to the undefined waiting state
        // That is called Deadlock

        -> the kind of action like dealock depends on kind of mutex, like fast or recursive, etc.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int count;
pthread_mutex_t mutex;

void *thread_function(void *data) {
    while (1) {
        pthread_mutex_lock(&mutex);
        pthread_mutex_lock(&mutex); // Checks mutex is avaliable or not, if not it will block calling theread execution
        // When a same thread going to lock the thread twice or more, the calling thread will go to the undefined waiting state
        // That is called Deadlock
        count = 0;
        count += 5;
        count += 20;
        printf("%d\n", count);
        pthread_mutex_unlock(&mutex);
        pthread_mutex_unlock(&mutex);
    }
}


int main() {

    pthread_t tid1, tid2;
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&tid1, NULL, thread_function, NULL);
    pthread_create(&tid2, NULL, thread_function, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_mutex_destroy(&mutex);

}