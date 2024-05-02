/**
 * Understand cearly
 * If first signal occurred, it will start executing for 10 seconds
 * In between other signal comes, it will interrupt the old signal, starts executing the recent/latest signal
 * Follows Last In First Out (Stack)
 * 
 * But it shouldn' be the case
 * FIrst should block the execution unitl it finishes its turn
 * This is possible with the member variable of sigaction strcuture which is mask
 * 
 * 
 * refer file 
 * sigaction_Adv_mask.c
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
    
    sigaction(SIGINT, &act, &old);
    sigaction(SIGTSTP, &act, &old);

    while (1) {
        printf("Inside main\n");
        sleep(1);
    }

}