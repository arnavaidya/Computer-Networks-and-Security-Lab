#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char send_data[1024];

    // Resolve hostname to IP address
    host = gethostbyname("127.0.0.1");
    if (host == NULL) {
        perror("Error resolving hostname");
        exit(1);
    }

    // Create UDP socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(server_addr.sin_zero), 8);

    while (1) {
        printf("Type Something (q or Q to quit): ");
        fgets(send_data, sizeof(send_data), stdin);
        send_data[strcspn(send_data, "\n")] = 0; // Remove newline

        if ((strcmp(send_data, "q") == 0) || strcmp(send_data, "Q") == 0) {
            break;
        }

        sendto(sock, send_data, strlen(send_data), 0,
               (struct sockaddr *)&server_addr, sizeof(struct sockaddr));
    }

    printf("Client exiting...\n");
    close(sock);
    return 0;
}
