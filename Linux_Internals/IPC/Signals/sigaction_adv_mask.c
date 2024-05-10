/**
 * Signal Masking
 * 
 * Solution for the problem in file named
 * sigaction_adv_issue.c
 * 
 * To resolve we use mask member
 * Refere manual page, there are some functions associated with it
 * 
 * man sigaddset -> used to add/ remove specific signals from 62 into this mask to block current signal
 * In betvween if another signal occurs
 * 
 * If we add all signals, Every signal gets blocked,If any signal arrived until it finishes that signal's action, 
   even if another signal arrived it will block, until earlier signal finishes its execution

*/

/**
 * It is not possible to generate signals with different action
 * So the solution for this is to give the specific signal to that process from another instance of 
   command prompt using the command
 *    --->>  kill -<Signal Number> <PID>
 *       Ex: kill -SIGINT  <PID>
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int signum, siginfo_t *info, void *context) {

    int i=0;
    while (i++< 10) {
        printf("\n Signal code : %d   running\n", info->si_signo);
        sleep(1);
    }

}

int main() {

    struct sigaction act, old;
    act.sa_sigaction = handler;

    act.sa_flags = SA_SIGINFO;
    // act.sa_mask  -> used

    sigemptyset(&(act.sa_mask));
    sigaddset(&(act.sa_mask), SIGTSTP); // SIG_TSTP signal blocked, means 
    // whatever signals we add into this set those signals get blocked when signal which is not in this set arrived
    // Here SIGTSTP gets blocked if some other signal comes, even it is occurred or it is running
    

    //IMP
    
    sigaction(SIGINT, &act, &old);
    sigaction(SIGTSTP, &act, &old);

    while (1) {
        printf("Inside main\n");
        sleep(1);
    }

}