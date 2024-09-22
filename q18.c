/*
============================================================================
Name : q18.c
Author : Akshat Abhishek Lal
Description : Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd1[2];  // Pipe for ls -l to grep
    int pipefd2[2];  // Pipe for grep to wc
    pid_t pid1, pid2, pid3;
    if (pipe(pipefd1) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    if (pipe(pipefd2) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    if ((pid1 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid1 == 0) {  // Child process for `ls -l`
        close(pipefd1[0]);  // Close read end of the first pipe
        dup2(pipefd1[1], STDOUT_FILENO);  // Redirect stdout to the first pipe
        close(pipefd1[1]);  // Close original write end
        execlp("ls", "ls", "-l", NULL);  // Execute `ls -l`
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    if ((pid2 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid2 == 0) {  // Child process for `grep`
        close(pipefd1[1]);  // Close write end of the first pipe
        dup2(pipefd1[0], STDIN_FILENO);  // Redirect stdin from the first pipe
        close(pipefd1[0]);  // Close original read end
        close(pipefd2[0]);  // Close read end of the second pipe
        dup2(pipefd2[1], STDOUT_FILENO);  // Redirect stdout to the second pipe
        close(pipefd2[1]);  // Close original write end
        execlp("grep", "grep", "^d", NULL);  // Execute `grep ^d`
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    if ((pid3 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid3 == 0) {  // Child process for `wc`
        close(pipefd1[0]);  // Close both ends of the first pipe
        close(pipefd1[1]);
        close(pipefd2[1]);  // Close write end of the second pipe
        dup2(pipefd2[0], STDIN_FILENO);  // Redirect stdin from the second pipe
        close(pipefd2[0]);  // Close original read end
        execlp("wc", "wc", "-l", NULL);  // Execute `wc -l`
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    close(pipefd1[0]);
    close(pipefd1[1]);
    close(pipefd2[0]);
    close(pipefd2[1]);
    wait(NULL);
    wait(NULL);
    wait(NULL);
    return 0;
}
/* SAMPLE OUTPUT
2
*/
