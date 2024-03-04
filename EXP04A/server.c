#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define PORT 8080
#define MAXLINE 1024
int main() {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    int len, n;
    len = sizeof(cliaddr);
    int size_mat[6];
    if ((recvfrom(sockfd, size_mat, sizeof(size_mat), MSG_WAITALL, (struct sockaddr *)&cliaddr, &len)) < 0) {
        perror("Size not received");
        return -1;
    }
    int r1 = size_mat[0];
    int c1 = size_mat[1];
    int r2 = size_mat[2];
    int c2 = size_mat[3];
    int matrix_A[r1][c1];
    int matrix_B[r2][c2];
    int matrix_R[r1][c2];
    if ((recvfrom(sockfd, matrix_A, sizeof(matrix_A), MSG_WAITALL, (struct sockaddr *)&cliaddr, &len)) < 0) {
        perror("Matrix A not received");
        return -1;
    }
    printf("Matrix A received\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            printf("%d ", matrix_A[i][j]);
        }
        printf("\n");
    }
    if ((recvfrom(sockfd, matrix_B, sizeof(matrix_B), MSG_WAITALL, (struct sockaddr *)&cliaddr, &len)) < 0) {
        perror("Matrix B not received");
        return -1;
    }
    printf("Matrix B received\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", matrix_B[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            matrix_R[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                matrix_R[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
        }
    printf("Matrix Result\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", matrix_R[i][j]);
        }
        printf("\n");
    }
    sendto(sockfd, matrix_R, sizeof(matrix_R), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, len);
    printf("Matrix sent to client.\n");
    return 0;
}

