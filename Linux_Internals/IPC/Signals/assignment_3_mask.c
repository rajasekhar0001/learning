/*
WAP to block certain signals from being received from command-line
 Pre-requisites:- 
• Knowledge about system calls, How to read and understand ‘man pages’.
• Good knowledge about signals and signal handling.
• Working of sigaction system call and signal masking.
Objective: -
• To understand importance of signal masking.
Requirements: -
1. Write a signal handler function for any signal, say SIGINT . 
2. While its running inside handler (use loop) block other signals(atleast 3) being 
received .
3. Use sa_mask from struct sigaction to set signals to be blocked (Refer man ).
4. To create a signal set use variable of sigset_t. 
5. To add or remove signals from set use sigaddset, sigdelset functions (refer man).
6. Process will receive blocked signals once its out from handler.
Sample execution: -
1. ./block_signal
Process 2345 waiting for signal..
press ctrl + c from terminal.
SIGINT received 
Inside handler 
Inside handler
.
.
.
2. Now open another terminal and send signal to process using kill command.
Bash$ kill ­SIGUSR1 2345
Bash$ kill ­SIGTERM 2345
Bash$ kill ­SIGABRT 2345
3. After exiting from handler will respond to blocked signal.
*/

/**
 * Solution:
 * No, it wil not respond to those signals until it finishes handling the running signals
 * 
 * There is always for the signals which are not in the mask set
*/


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
// #include

void signal_handler(int signum, siginfo_t *info, void * context) {
    int i=0;
    printf("Siganl %d received\n", signum);
    while(i++<25) {
        printf("Inside signal  %d\n", i);
        sleep(1);
    }
}

int main() {

    struct sigaction act, old;
    act.sa_flags = SA_SIGINFO;  // if this Macro is set as flag, we are using sigaction not signal
    act.sa_handler = &signal_handler;
    
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGTSTP);
    // sigaddset(&act.sa_mask, SIGINT);
    sigaddset(&act.sa_mask, SIGABRT);
    sigaddset(&act.sa_mask, SIGTERM);

    sigaction(SIGTSTP, &act, NULL);
    sigaction(SIGINT,&act, NULL);
    sigaction(SIGABRT,&act, NULL);
    sigaction(SIGTERM,&act, NULL);
    
    while (1) {

    }

}