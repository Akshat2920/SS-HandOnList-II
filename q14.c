/*
============================================================================
Name : q14.c
Author : Akshat Abhishek Lal
Description :   Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2]; 
    char buffer[100];
    const char *message = "Hello World";
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    printf("Writing to pipe\n");
    write(pipefd[1], message, strlen(message) + 1);
    close(pipefd[1]);
    
    read(pipefd[0], buffer, sizeof(buffer));
    printf("Reading from pipe: %s\n", buffer);
    close(pipefd[0]);

    return 0;
}
/* SAMPLE OUTPUT
Writing to pipe
Reading from pipe: Hello World
*/
