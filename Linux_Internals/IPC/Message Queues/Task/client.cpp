#include <iostream>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdlib.h>

using namespace std;

int main() {
    cout << "Started Client program\n";
    int msqid = msgget(1001, IPC_CREAT|0666);
    if (msqid == -1) {
        perror("msgget");
        exit(0);
    }
    int id=0;
    char buf[10] ;
    while (1) {
        cout << "Enter '0' to exit else other number: ";
        cin >> id;
        if (id ==0 ) {
            msgctl(msqid, IPC_RMID, 0);
            perror("msgctl");
            exit(0);
        }
        if (msgrcv(msqid, buf, 10, 0, 0) == -1) {
            perror("msgrcv");
            continue;
        }
        // int *data = (int*)buf;
        cout << buf << endl;
    }


}