#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int sigint) {
    switch (sigint) {
        case SIGINT:
            printf("SIGINT occured\n");
            signal(SIGSEGV, signal_handler);
            int *p =NULL;
            *p = 100;
            break;
        case SIGSEGV:
            printf("SIGSEGV arrived\n");
            break;

    }
}

int main() {
    // char *str = "15:10:59 2024/10/15";

    // struct tm dt;
    // strptime (str, "%H:%M:%S %Y/%m/%d", &dt);

    // printf("%d:%d:%d\n", dt.tm_hour, dt.tm_min, dt.tm_sec);

    // printf("%d/%d/%d\n", dt.tm_year+1900, dt.tm_mon+1, dt.tm_mday);


    signal(SIGINT, signal_handler);
    while(1) {}
}