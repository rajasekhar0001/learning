/**
 * sigaction() -> Refer manual
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


void sigaction_handler(int signum) {
    printf("SIGINT arrived %d\n", signum);
    
} 

int main() {

    struct sigaction act, old;
    act.sa_handler = sigaction_handler;
    // act.sigaction = function with 3 arguments; // this line or previos line one has to be used not both

    sigaction(SIGINT, &act, &old);

    while (1) {
        printf("INside main\n");
        sleep(1);
    }


}