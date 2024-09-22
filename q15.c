/*
============================================================================
Name : q15.c
Author : Akshat Abhishek Lal
Description : Write a simple program to send some data from parent to the child process.
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2]; 
    pid_t pid;
    char buffer[100]; 
    const char *message = "Sending from parent process";

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        close(pipefd[1]); 
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(pipefd[0]);
    } else {
        close(pipefd[0]); 
        printf("Message sent : %s\n", message);
        write(pipefd[1], message, strlen(message) + 1);  
        close(pipefd[1]);
    }

    return 0;
}
/* SAMPLE OUTPUT
Message sent : Sending from parent process
Child received: Sending from parent process

*/
