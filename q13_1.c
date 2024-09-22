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
void handle_sigstop(int signal_num) {
    printf("Received SIGSTOP, process stopped\n");
}
int main() {
    signal(SIGSTOP, handle_sigstop);
    printf("Process (PID: %d) is waiting for SIGSTOP\n", getpid());
    while (1) {
        printf("Process is running\n");
        sleep(2);  
    }
    return 0;
}
/* SAMPLE OUTPUT
Process (PID: 19849) is waiting for SIGSTOP
Process is running
Process is running
Process is running
Process is running
Process is running
Process is running
[1]+  Stopped                 ./a.out      
*/
