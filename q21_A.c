/*
============================================================================
Name : q21_A.c
Author : Akshat Abhishek Lal
Description :  Write two programs so that both can communicate by FIFO -Use two way communications. d
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
    int fd_send, fd_receive;
    char send_buffer[BUFFER_SIZE], receive_buffer[BUFFER_SIZE];
    if (mkfifo(FIFO_A_TO_B, 0666) == -1 || mkfifo(FIFO_B_TO_A, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }
    fd_send = open(FIFO_A_TO_B, O_WRONLY);
    if (fd_send == -1) {
        perror("open fifo_a_to_b");
        exit(EXIT_FAILURE);
    }
    fd_receive = open(FIFO_B_TO_A, O_RDONLY);
    if (fd_receive == -1) {
        perror("open fifo_b_to_a");
        exit(EXIT_FAILURE);
    }
    printf("Send a message : \n");
    while (1) {
        printf("Sending to B: ");
        fgets(send_buffer, BUFFER_SIZE, stdin);
        write(fd_send, send_buffer, strlen(send_buffer) + 1);
        read(fd_receive, receive_buffer, BUFFER_SIZE);
        printf("Program B: %s\n", receive_buffer);
    }
    close(fd_send);
    close(fd_receive);
    unlink(FIFO_A_TO_B);
    unlink(FIFO_B_TO_A);
    return 0;
}

/* SAMPLE OUTPUT
Send a message : 
Sending to B: sending message to B
Program B: Acknowledged 
You: ^C

*/
