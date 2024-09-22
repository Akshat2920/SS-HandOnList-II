/*
============================================================================
Name : q17.c
Author : Akshat Abhishek Lal
Description : Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

void execute_dup() {
    int pipefd[2];
    pid_t pid1, pid2;
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    if ((pid1 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid1 == 0) {  
        close(pipefd[0]);  
        dup(pipefd[1]);    
        close(pipefd[1]);  
        execlp("ls", "ls", "-l", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    if ((pid2 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid2 == 0) {  
        close(pipefd[1]);  
        dup(pipefd[0]);    
        close(pipefd[0]);  
        execlp("wc", "wc", NULL); 
        perror("execlp");
        exit(EXIT_FAILURE);
    }
    close(pipefd[0]);
    close(pipefd[1]);
    wait(NULL);  
    wait(NULL);
}

void execute_dup2() {
    int pipefd[2];
    pid_t pid1, pid2;
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    if ((pid1 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid1 == 0) { 
        close(pipefd[0]);  
        dup2(pipefd[1], STDOUT_FILENO);  
        close(pipefd[1]);  
        execlp("ls", "ls", "-l", NULL);  
        perror("execlp");
        exit(EXIT_FAILURE);
    }
    if ((pid2 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid2 == 0) {  
        close(pipefd[1]);  
        dup2(pipefd[0], STDIN_FILENO);  
        close(pipefd[0]);  
        execlp("wc", "wc", NULL);  
        perror("execlp");
        exit(EXIT_FAILURE);
    }
    close(pipefd[0]);
    close(pipefd[1]);
    wait(NULL);  
    wait(NULL);
}
void execute_fcntl() {
    int pipefd[2];
    pid_t pid1, pid2;
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    if ((pid1 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid1 == 0) {  
        close(pipefd[0]);  
        fcntl(pipefd[1], F_SETFL, O_NONBLOCK);  
        dup(pipefd[1]);   
        close(pipefd[1]);  
        execlp("ls", "ls", "-l", NULL);  
        perror("execlp");
        exit(EXIT_FAILURE);
    }
    if ((pid2 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid2 == 0) {  
        close(pipefd[1]);  
        fcntl(pipefd[0], F_SETFL, O_NONBLOCK);  
        dup(pipefd[0]);    
        close(pipefd[0]);  
        execlp("wc", "wc", NULL); 
        perror("execlp");
        exit(EXIT_FAILURE);
    }
    close(pipefd[0]);
    close(pipefd[1]);
    wait(NULL);  
    wait(NULL);
}

int main() {
    printf("Executing ls -l | wc using dup:\n");
    execute_dup();
  
    printf("\nExecuting ls -l | wc using dup2:\n");
    execute_dup2();
    
    printf("\nExecuting ls -l | wc using fcntl:\n");
    execute_fcntl();

    return 0;
}
/* SAMPLE OUTPUT
Executing ls -l | wc using dup:
total 184
-rwxrwxr-x 1 parallels parallels 70928 Sep 22 20:34 a.out
-rw-rw-r-- 1 parallels parallels   911 Sep 22 19:31 q10a.c
-rw-rw-r-- 1 parallels parallels  1003 Sep 22 19:32 q10b.c
-rw-rw-r-- 1 parallels parallels   931 Sep 22 19:43 q10c.c
-rw-rw-r-- 1 parallels parallels  1467 Sep 22 19:49 q11.c
-rw-rw-r-- 1 parallels parallels  1442 Sep 22 19:54 q12.c
-rw-rw-r-- 1 parallels parallels  1057 Sep 22 20:11 q13_1.c
-rw-rw-r-- 1 parallels parallels   944 Sep 22 20:11 q13_2.c
-rw-rw-r-- 1 parallels parallels   917 Sep 22 20:15 q14.c
-rw-rw-r-- 1 parallels parallels  1178 Sep 22 20:19 q15.c
-rw-rw-r-- 1 parallels parallels  1701 Sep 22 20:25 q16.c
-rw-rw-r-- 1 parallels parallels  3315 Sep 22 20:34 q17.c
-rw-rw-r-- 1 parallels parallels  1766 Sep 22 16:04 q1_a.c
-rw-rw-r-- 1 parallels parallels  1845 Sep 22 15:44 q1b.c
-rw-rw-r-- 1 parallels parallels  1717 Sep 22 15:48 q1c.c
-rw-rw-r-- 1 parallels parallels  2028 Sep 22 15:59 q2.c
-rw-rw-r-- 1 parallels parallels  1043 Sep 22 16:07 q3.c
-rw-rw-r-- 1 parallels parallels   777 Sep 22 16:17 q4.c
-rw-rw-r-- 1 parallels parallels  2417 Sep 22 16:20 q5.c
-rw-rw-r-- 1 parallels parallels   901 Sep 22 16:28 q6.c
-rw-rw-r-- 1 parallels parallels   965 Sep 22 16:32 q7.c
-rw-rw-r-- 1 parallels parallels   793 Sep 22 19:01 q8a.c
-rw-rw-r-- 1 parallels parallels   739 Sep 22 19:01 q8b.c
-rw-rw-r-- 1 parallels parallels   782 Sep 22 19:09 q8c.c
-rw-rw-r-- 1 parallels parallels   781 Sep 22 19:12 q8d.c
-rw-rw-r-- 1 parallels parallels  1038 Sep 22 19:15 q8e.c
-rw-rw-r-- 1 parallels parallels  1162 Sep 22 19:18 q8f.c
-rw-rw-r-- 1 parallels parallels  1099 Sep 22 19:20 q8g.c
-rw-rw-r-- 1 parallels parallels  1144 Sep 22 19:25 q9.c

Executing ls -l | wc using dup2:
     30     263    1693
     
Executing ls -l | wc using fcntl:
total 184
-rwxrwxr-x 1 parallels parallels 70928 Sep 22 20:35 a.out
-rw-rw-r-- 1 parallels parallels   911 Sep 22 19:31 q10a.c
-rw-rw-r-- 1 parallels parallels  1003 Sep 22 19:32 q10b.c
-rw-rw-r-- 1 parallels parallels   931 Sep 22 19:43 q10c.c
-rw-rw-r-- 1 parallels parallels  1467 Sep 22 19:49 q11.c
-rw-rw-r-- 1 parallels parallels  1442 Sep 22 19:54 q12.c
-rw-rw-r-- 1 parallels parallels  1057 Sep 22 20:11 q13_1.c
-rw-rw-r-- 1 parallels parallels   944 Sep 22 20:11 q13_2.c
-rw-rw-r-- 1 parallels parallels   917 Sep 22 20:15 q14.c
-rw-rw-r-- 1 parallels parallels  1178 Sep 22 20:19 q15.c
-rw-rw-r-- 1 parallels parallels  1701 Sep 22 20:25 q16.c
-rw-rw-r-- 1 parallels parallels  3315 Sep 22 20:34 q17.c
-rw-rw-r-- 1 parallels parallels  1766 Sep 22 16:04 q1_a.c
-rw-rw-r-- 1 parallels parallels  1845 Sep 22 15:44 q1b.c
-rw-rw-r-- 1 parallels parallels  1717 Sep 22 15:48 q1c.c
-rw-rw-r-- 1 parallels parallels  2028 Sep 22 15:59 q2.c
-rw-rw-r-- 1 parallels parallels  1043 Sep 22 16:07 q3.c
-rw-rw-r-- 1 parallels parallels   777 Sep 22 16:17 q4.c
-rw-rw-r-- 1 parallels parallels  2417 Sep 22 16:20 q5.c
-rw-rw-r-- 1 parallels parallels   901 Sep 22 16:28 q6.c
-rw-rw-r-- 1 parallels parallels   965 Sep 22 16:32 q7.c
-rw-rw-r-- 1 parallels parallels   793 Sep 22 19:01 q8a.c
-rw-rw-r-- 1 parallels parallels   739 Sep 22 19:01 q8b.c
-rw-rw-r-- 1 parallels parallels   782 Sep 22 19:09 q8c.c
-rw-rw-r-- 1 parallels parallels   781 Sep 22 19:12 q8d.c
-rw-rw-r-- 1 parallels parallels  1038 Sep 22 19:15 q8e.c
-rw-rw-r-- 1 parallels parallels  1162 Sep 22 19:18 q8f.c
-rw-rw-r-- 1 parallels parallels  1099 Sep 22 19:20 q8g.c
-rw-rw-r-- 1 parallels parallels  1144 Sep 22 19:25 q9.c



*/
