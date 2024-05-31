#include <stdio.h>
#include <time.h>

int main() {
    time_t t1;
    time (&t1);
    char *t = ctime(&t1);

    printf("%s\n", t);

    printf("%d\n", t1);
}