/**
 * alarm(time_in_Sec) -> generates the ALRM signal once the time is over
 * Until alrm finishes program has to be running
 * 
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handler (int signum) {
    printf("Clock reached ALARM ..  WAKE UP....\n");
}

int main() {

    signal(SIGALRM, handler);

    alarm(3);// wait for 3 seconds from the starting time of program and send the ALRM signal
    // Current process has to be active for atleast 3 seconds then only ALRM signal raised

    // Upto that current program has to be alive, two ways
    /**
     * i) USing some loop
     * ii) using pause() 
    */

   pause(); // Block current process execution until it receives some signal

    // while (1) {
    //     printf("Inside main\n");
    //     sleep(1);
    // }

}