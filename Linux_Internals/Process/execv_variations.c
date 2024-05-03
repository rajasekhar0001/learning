/**
 * execv -> same like execl (refer there)
 * Addiitionally
 * -> second argument in a variable number of arguments
 * -> It is array of strings which contain command with options
 * Note: No use of writing any statements after exec() variants
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    char *cmd[] ={"ls", "-l", NULL};    // NULL is mandatory
    #if 0
    execv("/bin/ls", cmd);
    perror("execv");
    #else 
    execvp("ls", cmd);
    perror("execvp");
    #endif

    printf("Will it executed\n"); // if execv or execvp fails, control comes here
}