/*
============================================================================
Name : q13_1.c
Author : Akshat Abhishek Lal
Description :   Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    pid_t pid;
    printf("Enter the PID of the process to send SIGSTOP: ");
    scanf("%d", &pid);
    if (kill(pid, SIGSTOP) == 0) {
        printf("SIGSTOP signal sent to process with PID: %d\n", pid);
    } else {
        perror("Failed to send SIGSTOP");
    }
    return 0;
}
/* SAMPLE OUTPUT
Enter the PID of the process to send SIGSTOP: 19849
SIGSTOP signal sent to process with PID: 19849

*/
