/*
============================================================================
Name : q11.c
Author : Akshat Abhishek Lal
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal 
use sigaction system call.
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void reset_sigint(int signal_num) {
    if (signal_num == SIGALRM) {
        printf("\nResetting SIGINT to default action\n");
        struct sigaction sa_default;
        sa_default.sa_handler = SIG_DFL;  
        sigemptyset(&sa_default.sa_mask); 
        sa_default.sa_flags = 0;         
        sigaction(SIGINT, &sa_default, NULL);  // Reset SIGINT to default action
    }
}

int main() {
    struct sigaction sa_ignore;
    sa_ignore.sa_handler = SIG_IGN;       
    sigemptyset(&sa_ignore.sa_mask);      
    sa_ignore.sa_flags = 0;               
    sigaction(SIGINT, &sa_ignore, NULL);
    printf("SIGINT (Ctrl+C) will be ignored\n");
    
    signal(SIGALRM, reset_sigint); 
    alarm(5);  
    while (1) {
        printf("Press Ctrl+C to test SIGINT\n");
        sleep(2); 
    }
    return 0;
}
/* SAMPLE OUTPUT
SIGINT (Ctrl+C) will be ignored
Press Ctrl+C to test SIGINT
^C^CPress Ctrl+C to test SIGINT
^C^C^C^CPress Ctrl+C to test SIGINT
^C^C
Resetting SIGINT to default action
Press Ctrl+C to test SIGINT
^C

*/
