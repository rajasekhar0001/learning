/**
 * execl -> function replaces the program running in a process with another program
 * Execution -> When this function is executed it stops executing current program and execute the new program which is passed as arguments to exec()
 *           -> On failure (Process continues ruunnig the current program taht is main)
 * All exec variations are same like this only
 * Note: No use of writing any statements after exec() variants
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

    #if 0
    execl("/bin/ls", "ls", NULL);  // path, and variable number of arguments
    perror("execl");
    printf("CHecking\n");       // Not executable line if exec() function executes without failure
    #else
    execlp("ls","ls", "-l", NULL);  // file name, and variable numbe rof arguments, NULL at the end which endicates end
    perror("execlp");
    #endif

}