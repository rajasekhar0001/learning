#include <iostream>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdlib.h>

using namespace std;

int main() {
    cout << "Started Server program\n";
    int msqid = msgget(1001, IPC_CREAT|0666);
    if (msqid == -1) {
        perror("msgget");
        exit(0);
    }
    char str[5];
    while (1) {
        cout << "Enter a number : ";
        cin >> str;
        
        if (msgsnd(msqid, (void*)str, 5, 0)==-1) {
            perror("msgsnd");
            continue;
        }
        perror("msgsnd");

    }
}