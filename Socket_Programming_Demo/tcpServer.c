#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main() {
    int sock, connected, bytes_recieved, true = 1;
    char send_data[1024], recv_data[1024];
    struct sockaddr_in server_addr, client_addr;
    socklen_t sin_size;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket");
        exit(1);
    }

    // Set socket options
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &true, sizeof(int)) == -1) {
        perror("Setsockopt");
        exit(1);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(server_addr.sin_zero), 8);

    // Bind the socket
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("Unable to bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 5) == -1) {
        perror("Listen");
        exit(1);
    }

    printf("\nTCP Server Waiting for client on port 5000\n");
    fflush(stdout);

    while (1) {
        sin_size = sizeof(struct sockaddr_in);
        connected = accept(sock, (struct sockaddr *)&client_addr, &sin_size);

        if (connected == -1) {
            perror("Accept");
            continue;
        }

        printf("\nConnection received from (%s , %d)",
               inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            printf("\nSEND (q or Q to quit): ");
            fflush(stdout);

            // Use fgets instead of gets (safer)
            if (fgets(send_data, sizeof(send_data), stdin) == NULL)
                continue;

            // Remove newline character from input
            send_data[strcspn(send_data, "\n")] = 0;

            if (strcmp(send_data, "q") == 0 || strcmp(send_data, "Q") == 0) {
                send(connected, send_data, strlen(send_data), 0);
                close(connected);
                break;
            } else {
                send(connected, send_data, strlen(send_data), 0);
            }

            // Receive data
            bytes_recieved = recv(connected, recv_data, sizeof(recv_data) - 1, 0);
            if (bytes_recieved <= 0) {
                printf("\nClient disconnected.\n");
                close(connected);
                break;
            }

            recv_data[bytes_recieved] = '\0';

            if (strcmp(recv_data, "q") == 0 || strcmp(recv_data, "Q") == 0) {
                close(connected);
                break;
            } else {
                printf("\nRECEIVED DATA: %s", recv_data);
                fflush(stdout);
            }
        }
    }

    close(sock);
    return 0;
}
