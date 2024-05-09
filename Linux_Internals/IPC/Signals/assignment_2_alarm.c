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
#include <fcntl.h>
#include <string.h>

int i;

void signal_handler(int signum) {
    printf("Wake Up Alarm!\n");
    i=0;    // alarm completed

}

int main(int argc, char* argv[]) {

    if (argc == 1) {
        printf("No arguments passed\n");
        exit(0);
    }

    signal(SIGALRM, signal_handler);

    // process given input
    struct tm dateTime;
    struct tm *currentTime;
    memset(&dateTime, 0, sizeof(dateTime));
    char dateTime_str[255];

    time_t current_time;
    time(&current_time);
    currentTime = gmtime(&current_time);
    // printf()
    if (argv[2] != NULL) {
        sprintf(dateTime_str, "%s %s",argv[2], argv[1]);
        strptime(dateTime_str, "%Y/%m/%d %H:%M:%S", &dateTime);
    }
    else {
        strptime(argv[1], "%H:%M:%S", &dateTime);
        dateTime.tm_year = currentTime->tm_year;
        dateTime.tm_mon = currentTime->tm_mon;
        dateTime.tm_mday = currentTime->tm_mday;
    }
    printf("Curent time -> %d/%d/%d  %d:%d:%d\n", currentTime->tm_year+1900, currentTime->tm_mon+1, currentTime->tm_mday, currentTime->tm_hour, currentTime->tm_min, currentTime->tm_sec);
    printf("Set Alarm at ->  %d/%d/%d  %d:%d:%d\n", dateTime.tm_year+1900, dateTime.tm_mon+1, dateTime.tm_mday, dateTime.tm_hour, dateTime.tm_min, dateTime.tm_sec);
    long diffrenceBetweenTimes = mktime(&dateTime) - mktime(currentTime);


    // printf("Difference in time in seconds:  %ld\n", diffrenceBetweenTimes);
    if (diffrenceBetweenTimes < 0) {
        printf("Choose the future date\n");
        exit(1);
    }

    printf("Time in seconds in a day: %d\n", 60*60*24);
    if (diffrenceBetweenTimes < 60*60*24 && dateTime.tm_mday+1 >= currentTime->tm_mday && dateTime.tm_mon >= currentTime->tm_mon && dateTime.tm_year >= currentTime->tm_year ) {
        printf("Set ALARM for %d:%d:%d today.\n", dateTime.tm_hour, dateTime.tm_min, dateTime.tm_sec);
    }
    else
    {
        printf("Set alarm at ->  %d:%d:%d  on %d/%d/%d\n", dateTime.tm_hour, dateTime.tm_min, dateTime.tm_sec, dateTime.tm_year + 1900, dateTime.tm_mon + 1, dateTime.tm_mday);
    }
    alarm(diffrenceBetweenTimes);
    i=1;        // alarm set
    while (i==1) {
    }

    while (1) {
        int option;
        printf("Choose an option: \n1. Snooze    2. Stop\n");
        scanf("%d", &option);
        switch(option) {
            case 1:
            {
                int minutes;
                printf("Enter Snooze time in minutes: ");
                scanf("%d", &minutes);
                if (diffrenceBetweenTimes+(minutes*60) < 60 * 60 * 24 && dateTime.tm_mday + 1 >= currentTime->tm_mday && dateTime.tm_mon >= currentTime->tm_mon && dateTime.tm_year >= currentTime->tm_year)
                {
                    printf("Set ALARM for %d:%d:%d today.\n", dateTime.tm_hour, dateTime.tm_min, dateTime.tm_sec);
                }
                else {
                    printf("Set alarm at ->  %d:%d:%d  on %d/%d/%d\n", dateTime.tm_hour, dateTime.tm_min, dateTime.tm_sec, dateTime.tm_year+1900, dateTime.tm_mon+1, dateTime.tm_mday);
                }
                alarm(minutes*60);  // takes arguments in terms of seconds ( conversion )
                i = 1;
                while (i == 1)
                {
                }
                break;
            }
            case 2:
                printf("ALARM stoped\n");
                exit(1);
            default: 
                printf("Enter valid option\n");
        }
    }
}