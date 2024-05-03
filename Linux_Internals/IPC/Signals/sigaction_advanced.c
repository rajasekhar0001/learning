/**
 * sigaction() -> Refer manual
 * 
 * Give SIGINT signal from other shell using -> kill -2(PID of signal which we are handling)  <PID of process> (to which we are sending)
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


void sigaction_handler(int signum, siginfo_t* info, void* uncontext) {
    printf("SIGINT arrived and the sender PID : %d\n", info->si_pid);
    
} 

int main() {

    struct sigaction act, old;
    act.sa_flags = SA_SIGINFO;
    // act.sa_handler = sigaction_handler;
    // act.sa_sigaction = function with 3 arguments; // this line or previos line one has to be used not both
    act.sa_sigaction = sigaction_handler; 

    sigaction(SIGINT, &act, NULL);

    while (1) {
        printf("INside main\n");
        sleep(1);
    }


}