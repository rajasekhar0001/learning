#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    printf("started\n");
    int ret = fork();
    if (ret ==0 ) {
        // child process
        printf("Child process: PID : %d\n", getpid());
        int ret_c = fork();
        if (ret_c == 0) {
            // nested child 
            printf("Nested child : PID : %d\n", getpid());
            sleep(10);

        }
        else if (ret_c > 0) {
            printf("Child parent: PID : %d\n\n", getpid());
            sleep(5);
        }
    }
    else if (ret > 0) {
        printf("Parent orocess\n");
        sleep(15);
    }
}