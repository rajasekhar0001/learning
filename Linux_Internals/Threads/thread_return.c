/**
 * Thread return value
 * 1) Static variable
 * 2) Using a structure (passing structure variable as argument to thread function and result is one member in that structure variable)
 * 3) Using dynamic memory allocation
 * 4) Hackway method
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void * fun(void *data) {

    int d = *((int*)data);
    printf("data inside thread : %d\n", d);
    // static int ret;      // using static variable
    // ret += 10 + d;

    // int *ret = malloc(sizeof(int));  // Using dynamic memory allocation
    // *ret = 100;
 
    // Hackway method
    

    return (void*) (long) d;  // This is Hackway method -> mainly use of casting here

    // return ret;

}

int main() {

    int data = 10;

    pthread_t t1;
    pthread_create (&t1, NULL, fun, &data); // passing arguments t thread

    // It can also be passed as structure

    int *ret;
    pthread_join(t1, (void**)&ret); // accepting return value from thread

    printf("RET from thread : %ld\n", sizeof(ret));
}