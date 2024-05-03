/**
 * ALONG WITH FORK SYSTEM CALL
 * Usage-> CHild to become zombie when terminated early
 * SA_NOCLDWAIT -> To avoid child to become zombie, we use this, insted of becoming Zombie gets terminated completely
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum, siginfo_t *info, void *context) {
    printf("SIGCHLD notified and the exit status is %d\n", info->si_status);
}

int main() {

    struct sigaction act;
    act.sa_sigaction = handler;
    act.sa_flags = SA_SIGINFO | SA_NOCLDWAIT;

    // REgostering the signal
    sigaction(SIGCHLD, &act, NULL);

    int ret = fork();
    if (ret == 0) {
        printf("Child is running\n");
        sleep(3);    
        printf("Chidl terminated\n");
        exit(4); // if it is not there the result looks like 0 not 4
    }
    else if (ret > 0) {
        printf("Parent is running\n");
        pause(); // Using for below problem, in case of signal, pause() gets interrupted 
        // If sleep is earlier, sleep gets interrupted


        sleep(10);                           // if we use only sleep, parent also gets terminated when child terminated 
        // This is because sleep will be interrupted when some signal occurs
        
        printf("Parent terminated\n");
    }

}
