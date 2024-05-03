/**
 * Analyzing how control goees if we use fork() to create child process
 * 
 * Outside of if blocks is being executed by all processes, if we won't exit from that process 
   inside if/ if else blocks
 * 
*/

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>

int main() {

    int ret = fork();

    if (ret == 0) {
        printf("Child process in :   PID : %d\n", getpid());
    }
    else if (ret > 0) {
        printf("Parent process :   PID : %d\n", getpid());
    }
    else {
        perror("fork");
    }
    // Outside of if blocks is being executed by all processes until we terminate in
    // that block using exit()

    printf("Outside of if blocks :  PID : %d\n", getpid());

}