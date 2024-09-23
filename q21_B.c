/*
============================================================================
Name : q21_B.c
Author : Akshat Abhishek Lal
Description :  Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO_A_TO_B "/tmp/fifo_a_to_b"
#define FIFO_B_TO_A "/tmp/fifo_b_to_a"
#define BUFFER_SIZE 100

int main() {
    int fd_receive, fd_send;
    char receive_buffer[BUFFER_SIZE], send_buffer[BUFFER_SIZE];
    fd_receive = open(FIFO_A_TO_B, O_RDONLY);
    if (fd_receive == -1) {
        perror("open fifo_a_to_b");
        exit(EXIT_FAILURE);
    }
    fd_send = open(FIFO_B_TO_A, O_WRONLY);
    if (fd_send == -1) {
        perror("open fifo_b_to_a");
        exit(EXIT_FAILURE);
    }
    printf("Waiting for messages from Program A\n");
    while (1) {
        read(fd_receive, receive_buffer, BUFFER_SIZE);
        printf("Program A: %s\n", receive_buffer);
        printf("Sending to A :");
        fgets(send_buffer, BUFFER_SIZE, stdin);
        write(fd_send, send_buffer, strlen(send_buffer) + 1);
    }
    close(fd_receive);
    close(fd_send);
    unlink(FIFO_A_TO_B);
    unlink(FIFO_B_TO_A);

    return 0;
}
/* SAMPLE OUTPUT
Waiting for messages from Program A
Program A: sending message to B

Sending to A :Acknowledged           
^C
*/
