/**
 * signal()  -> Not preferred, its usage may not be same in every OS
 * typedef void (*sighandler_t) (int);  //->  function pointer
 * 
 * signhandler_t signal(int signum, sighandler_t handler)  -> used to register some functionality to some signal number
 * 62 signals cen be handled except 2 signals which are SIGKILL and SIGSTOP
 * 
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void signal_handler(int signum) {
    // printf("SIGINT arrived\n");
    switch (signum) {
        case SIGINT: 
            printf("SIGINT received\n");
            break;
        case SIGSEGV:
            printf("SIGSEGV received\n");
            break;
        case SIGTSTP:
            printf("SIGTSTP received\n");
            break;
        // default:

    }
}

int main() {
    
    // Regustering signal handler for the signal SIGINT (occurred when we preess CTRL + C while some code is running)
    signal(SIGINT, signal_handler);
    signal(SIGSEGV, signal_handler);
    signal(SIGTSTP, signal_handler);

   

    while (1) {
        printf("inside loop\n");
        sleep(1);
    }
}