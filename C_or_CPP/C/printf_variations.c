#include <stdio.h>

int main() {
    int f = printf("Hello %s\n", "raja");


    // File *fp = fopen()

    int s = fprintf(stdout, "Hello %s\n", "sekhar");    // can be used in case of files, 
    // to write data in which ever form we want to like int, char, etc.
    // fscanf is also similar to read in which ever form we want to

    char str[20];

    int t = sprintf(str, "hhhhh %s", "reddy");

    printf("String after sprintf() :  %s\n", str);

    char str2[10];

    int fo  = snprintf(str2, 5, "Hello %s", "raja");

    printf("after snprintf( ) : %s\n", str2);



    printf("%d %d %d %d\n", f, s, t, fo);

}