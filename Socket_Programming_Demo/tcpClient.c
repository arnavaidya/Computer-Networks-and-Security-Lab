#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main() {
    int sock, bytes_recieved;
    char send_data[1024], recv_data[1024];
    struct hostent *host;
    struct sockaddr_in server_addr;

    // Get host info
    host = gethostbyname("127.0.0.1");
    if (host == NULL) {
        perror("Error resolving hostname");
        exit(1);
    }

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket");
        exit(1);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(server_addr.sin_zero), 8);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("Connect");
        exit(1);
    }

    while (1) {
        // Receive data from server
        bytes_recieved = recv(sock, recv_data, sizeof(recv_data) - 1, 0);
        if (bytes_recieved <= 0) {
            printf("\nServer disconnected.\n");
            close(sock);
            break;
        }

        recv_data[bytes_recieved] = '\0';

        // Exit if server sends "q" or "Q"
        if (strcmp(recv_data, "q") == 0 || strcmp(recv_data, "Q") == 0) {
            printf("\nServer requested to end connection.\n");
            close(sock);
            break;
        }

        printf("\nReceived data: %s", recv_data);
        printf("\nSEND (q or Q to quit): ");
        fflush(stdout);

        // Use fgets instead of gets (safer)
        if (fgets(send_data, sizeof(send_data), stdin) == NULL)
            continue;

        // Remove newline character from input
        send_data[strcspn(send_data, "\n")] = 0;

        // Send data to server
        send(sock, send_data, strlen(send_data), 0);

        // Exit if client sends "q" or "Q"
        if (strcmp(send_data, "q") == 0 || strcmp(send_data, "Q") == 0) {
            printf("\nClosing connection.\n");
            close(sock);
            break;
        }
    }

    return 0;
}
