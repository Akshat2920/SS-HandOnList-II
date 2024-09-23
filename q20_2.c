/*
============================================================================
Name : q20_2.c
Author : Akshat Abhishek Lal
Description :  Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define FIFO_NAME "/tmp/my_fifo"
#define BUFFER_SIZE 100

int main() {
    int fd;
    char buffer[BUFFER_SIZE];
    fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    printf("Waiting for messages\n");
    while (read(fd, buffer, BUFFER_SIZE) > 0) {
        printf("Received: %s", buffer);
    }
    close(fd);
    unlink(FIFO_NAME);
    return 0;
}

/* SAMPLE OUTPUT
Waiting for messages
Received: sending message to programme 2 via keyboard from programme 1
Received: sending another message

*/
