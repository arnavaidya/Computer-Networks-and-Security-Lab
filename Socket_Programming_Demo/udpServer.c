#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int sock;
    socklen_t addr_len;
    int bytes_read;
    char recv_data[1024];
    struct sockaddr_in server_addr, client_addr;

    // Create UDP socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("Socket");
        exit(1);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(server_addr.sin_zero), 8);

    // Bind socket
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("Bind");
        exit(1);
    }

    addr_len = sizeof(struct sockaddr);
    printf("\nUDP Server Waiting for client on port 5000...\n");
    fflush(stdout);

    while (1) {
        // Receive data from client
        bytes_read = recvfrom(sock, recv_data, sizeof(recv_data) - 1, 0,
                              (struct sockaddr *)&client_addr, &addr_len);

        if (bytes_read < 0) {
            perror("Receive failed");
            continue;
        }

        recv_data[bytes_read] = '\0'; // Null terminate received data

        // Print received message
        printf("\n(%s , %d) said: %s",
               inet_ntoa(client_addr.sin_addr),
               ntohs(client_addr.sin_port),
               recv_data);
        fflush(stdout);

        // Exit condition
        if (strcmp(recv_data, "exit") == 0 || strcmp(recv_data, "q") == 0) {
            printf("\nServer shutting down...\n");
            break;
        }
    }

    close(sock);
    return 0;
}
