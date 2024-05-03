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
    int ret1 = fork();
    if (ret == 0) {
        if (ret1 == 0) {
            printf("ret  child  ret1 child :   PID : %d   PPID : %d\n", getpid(), getppid());
        }
        else if (ret1 > 0) {
            printf("ret child  ret1 parent :   PID : %d   PPID : %d\n", getpid(), getppid());
            sleep(1);
        }
    }
    else if (ret > 0) {
        if (ret1 == 0) {
            printf("ret parent  ret1 child :   PID : %d   PPID : %d\n", getpid(), getppid());
            
        }
        else if (ret1 > 0) {
            printf("ret parent  ret1 parent :   PID : %d   PPID : %d\n", getpid(), getppid());
            sleep(1);
        }
    }

    // printf("Outside of if blocks :  PID : %d\n", getpid());

}