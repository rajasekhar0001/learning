/**
 * SIGIGN -> SIgnal Ignore,  Ex: SIgnal will be ignored means no response
 * SIG_DFL -> SIgnal default, if we do this for a signal, it will use its default action
 * Ex: Ctrl +C -> termination is default like that
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler (int signum) {
    printf("SIGINT arrived\n");
    // signal(SIGINT, SIG_IGN);        // SIGINT signal is being ignored means no rsponse for SIGINT

    signal(SIGINT, SIG_DFL);  // SIG_DFL means signal default, 
    // SIG_DFL -> SIGINT default action is termination
}

int main() {

    printf("Before registering signal\n");


    // Registering the signal for handling with different implenetation
    signal(SIGINT, handler);

    while (1) {
        printf("Inisde main\n");
        sleep(1);
    }
}