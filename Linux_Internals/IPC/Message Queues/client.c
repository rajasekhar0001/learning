#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

int main() {
    printf("IPC using Message Queues\n");
    int msg_id;
    if ((msg_id = msgget(111, IPC_CREAT | 0666)) == -1) {
        perror("msgget");
        exit(0);
    }
    char buf[100];
    int ret = msgrcv(msg_id, buf, 15, 0, 0);
    if (ret == -1) {
        perror("msgsnd");
        exit(0);
    }

    printf("Receive done with return : %d\n", ret);
    printf("REceived data is : %s\n", buf);

    if (msgctl(msg_id, IPC_RMID, NULL)==-1) {
        perror("msgctl");
        exit(0);
    }
    printf("Message queue deleted\n");

}