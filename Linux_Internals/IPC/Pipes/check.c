#include <stdio.h>
#include <string.h>

int main() {
    char *argv[5] = {"ls", "-l", "|", "wc"};
    char *cmd[5];
    for (int i=0;i<4; i++) {
        cmd[i] = argv[i];
    }
    // cmd[4] = NULL;

    for (int i=0;i<4;i++) {
        printf("%s   ", argv[i]);

    }
    printf("\n");
}