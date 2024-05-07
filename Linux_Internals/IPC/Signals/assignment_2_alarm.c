/*
AP to implement alarm with snooze for given time and date using SIGALRM
 Pre-requisites:- 
• Knowledge about system calls, How to read and understand ‘man pages’.
• Good knowledge about signals and signal handlers.
• Working of alarm system calls.
Objective: -
• To understand signals and time related system calls.
Requirements: -
1. User gives the time and date from command-line arguments.
2. Validate the time eg: Do not go behind the current time. 
3. Date is an option, if user not providing date consider it as today.
4. In handler, avoid all user communication(printf, scanf etc) and loops.
Make it minimal as possible.
5. After the alarm expires, display a ALARM message along with date and time.
6. Prompt the user whether he wants to stop or snooze.
7. If user selects stop, terminate the program.
8. If user selects snooze, prompt for snooze time in minutes.
 > If user enters the time, reset the alarm to the entered time in minutes
 > If user doesn't enter time, default the snooze time to 1 mins
Sample execution: -
1. ./alarm (No arguments)
Error: No arguments passed
Usage: ./alarm <hh:mm> [dd/mm/yy]
2. ./alarm 30:15
Error: Invalid time
3. ./alarm 22:10
set alarm for 10:10 PM for today
4. ./alarm 22:10 02/03/16
set alarm for 10:10 PM for today
5. When alarm occurs
Wake­up...Alarm..!!
1. Snooze     2. Exit
if user select 1
Enter snooze time
2
After 2 mins above process will repeat until user gives exit
Hints:
• Use strptime to convert string to time (Refer man page)
• Other useful functions are localtime, mktime, strptime
*/


#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void signal_handler(int signum, siginfo_t *info, void *context) {
    // siginfo_t structure variable contains the information related to the signal

    printf("Segmentation fault... !\n");

    printf("Address %p caused error\n", info->si_addr);
    exit(0);

}

int main(int argc, char* argv[]) {

    if (argc == 1) {
        printf("No arguments passed\n");
        exit(0);
    }
    struct sigaction* act, *old;

    act->sa_sigaction = signal_handler;
    act->sa_flags = SA_SIGINFO;

    sigaction(SIGALRM, act, NULL);

    // process time
    struct tm tm;

    int ret = strptime(argv[1], "%H:%M", &tm);

    struct tm date;
    if (argv[2] != NULL) {
        strptime(argv[2], "%y/%m", &date);
        printf("date:  %d/%d/%d\n", date.tm_year, date.tm_mon, date.tm_yday);
    }
    printf("%d  : %d\n", tm.tm_hour, tm.tm_min);
    if ((tm.tm_hour >= 24 || tm.tm_hour < 0) || (tm.tm_min >= 60 || tm.tm_min <0)) {
        printf("Error Invalid date\n");
    }

    long current_time_in_sec = time(NULL);

    if (argv[2] ==NULL) {
        struct tm *current_time_tm  = gmtime(&current_time_in_sec);
    }

    printf("%ld   %ld\n", current_time_in_sec, 0);
    // while (1) {   
    
    // }
}