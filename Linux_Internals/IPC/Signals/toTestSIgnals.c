#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   // for sleep

int main() {
    FILE *fp = fopen("numbers.txt", "w");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    int num = 1;
    while (1) {
        fprintf(fp, "%d\n", num);
        fflush(fp);   // ensure data is written to file immediately
        num++;
        sleep(1);     // wait for 1 second
    }

    fclose(fp);  // technically unreachable, but good practice
    return 0;
}
