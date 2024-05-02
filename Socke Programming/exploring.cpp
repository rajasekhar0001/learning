#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <net/if.h>
#include <sys/types.h>
#include <arpa/inet.h>

int main() {
    int index = if_nametoindex("eth0.4");

    printf("%d\n", index);
    index = if_nametoindex("eth0.5");

    printf("second :  %d\n", index);

    printf("%d   %d   %d\n", SOL_SOCKET, IPV6_MULTICAST_IF, IPV6_MULTICAST_LOOP);

}