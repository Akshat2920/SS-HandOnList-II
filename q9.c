/*
============================================================================
Name : q9.c
Author : Akshat Abhishek Lal
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void reset_sigint(int signal_num) {
    if (signal_num == SIGALRM) {
        printf("Resetting SIGINT to default action\n");
        signal(SIGINT, SIG_DFL); 
    }
}
int main() {
    signal(SIGINT, SIG_IGN);
    printf("SIGINT is ignored. Try pressing Ctrl+C...\n");
    signal(SIGALRM, reset_sigint); 
    alarm(5);  

    while (1) {
        printf("Waiting... Press Ctrl+C to test SIGINT\n");
        sleep(2);
    }
    return 0;
}
/* SAMPLE OUTPUT
SIGINT is ignored. Try pressing Ctrl+C...
Waiting... Press Ctrl+C to test SIGINT
^C^CWaiting... Press Ctrl+C to test SIGINT
^C^C^CWaiting... Press Ctrl+C to test SIGINT
^C^CResetting SIGINT to default action
Waiting... Press Ctrl+C to test SIGINT
^C

*/
