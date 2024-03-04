#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080
int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    printf("Enter a string: ");
    char str_normal[100];
    scanf("%s", str_normal);
    char *str_ptr;
    str_ptr = &str_normal[0];
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.10.6.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ address not supported\n");
        return -1;
    }
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("\nConnection Failed");
        return -1;
    }
    send(sock, str_ptr, strlen(str_ptr), 0);
    printf("String sent: %s\n", str_ptr);
    valread = read(sock, buffer, 1024);
    printf("Response from server: %s\n", buffer);
    close(sock);
    return 0;
}
