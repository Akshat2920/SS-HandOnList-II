/*
============================================================================
Name : q20_1.c
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
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }
    fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    printf("Enter a message to send:\n");
    while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        write(fd, buffer, BUFFER_SIZE);
    }
    close(fd);
    unlink(FIFO_NAME);
    return 0;
}

/* SAMPLE OUTPUT
Enter a message to send :
sending message to programme 2 via keyboard from programme 1
sending another message
^C
*/
