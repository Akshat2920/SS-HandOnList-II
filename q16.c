/*
============================================================================
Name : q16.c
Author : Akshat Abhishek Lal
Description : Write a program to send and receive data from parent to child vice versa. Use two way
communication
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd1[2];  //parent -> child
    int pipefd2[2];  //child -> parent
    pid_t pid;
    char buffer[100];  
    if (pipe(pipefd1) == -1 || pipe(pipefd2) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        close(pipefd1[1]);  
        close(pipefd2[0]); 
        read(pipefd1[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        printf("Sending message to parent\n");
        const char *response = "Sent from child";
        write(pipefd2[1], response, strlen(response) + 1);
        close(pipefd1[0]);
        close(pipefd2[1]);
    } else {
        close(pipefd1[0]);  
        close(pipefd2[1]);  
        printf("Sending message to child from parent\n");
        const char *message = "Sent from parent";
        write(pipefd1[1], message, strlen(message) + 1);
        read(pipefd2[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);
        close(pipefd1[1]);
        close(pipefd2[0]);
    }

    return 0;
}
/* SAMPLE OUTPUT
Sending message to child from parent
Child received: Sent from parent
Sending message to parent
Parent received: Sent from child
*/
