#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *add(void *data) {
    for (int i=0;i < 20;i++) {
        printf("Inside thread\n");
    }
}

int main() {
    pthread_t t1;
    pthread_create(&t1, NULL, add, NULL);
    printf("Main thread\n");

    pthread_join(t1, NULL);  // check with and without
    printf("Outside cof created thread\n");


}