/**
 * Thread attribute
 * if attribute (attr) is passed as NULL, the thread will be created with JOINABLE STATE (Default state)
 * 
*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *add(void *data) {
    for (int i=0;i<25;i++) {
        printf("Inside thread\n");
    }
}

int main() {
    pthread_t t1;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);    // Makes the attr to configure in detached state
    // By default thread is created in JOINABLE state
    
    pthread_create(&t1, &attr, add, NULL);

    // pthread_join(t1, NULL); // No use of using pthread_join(t1, NULL);

    // sleep(5); // Not recommended to use

    // while(1);  // Not recommended


    printf("After completion of thread execution\n");
    pthread_attr_destroy(&attr);

    pthread_exit(NULL); // Used to terminate calling thread
    // IF main thread is terminated by using this function, other threads will continue execution
    // good to use
    // Argument passed is considered as a return value

}