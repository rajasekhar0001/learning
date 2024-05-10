/*
WAP to print the address which causing segmentation fault.
 Pre-requisites:- 
• Knowledge about system calls, How to read and understand ‘man pages’.
• Good knowledge about signals and signal handling.
• Working of sigaction system calls.
Objective: -
• To understand working of signal handling.
Requirements: -
1. Write a signal handler function to print address which caused seg-fault(SIGSEGV).
2. Use sigaction system call to register signal. 
3. Use struct siginfo from sa_sigaction to print address (Read man page).
4. Create a segmentation fault from code. 
5. When error occurs program should print address and exit.
Sample execution: -
1. ./sigsegv
Segmentation fault ..!!
Address 0x123456 caused error
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void signal_handler(int signum, siginfo_t *info, void *context) {
    // siginfo_t structure variable contains the information related to the signal

    printf("Segmentation fault... !\n");

    printf("Address %p caused error\n", info->si_addr);
    exit(0);
}

int main() {

    struct sigaction* act, *old;

    act->sa_sigaction = signal_handler;
    act->sa_flags = SA_SIGINFO;

    sigaction(SIGSEGV, act, NULL);

    int *p =(int *) 0x5676; // Some address which is not belong to this pointer, randomly given 
    *p=10;  // This line causes Segmentation fault error 

    while (1) {     // loop not required
        
    }

}