/*
============================================================================
Name : q10b.c
Author : Akshat Abhishek Lal
Description : Write a separate program using sigaction system call to catch the following signals.
b. SIGINT
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signal_num, siginfo_t *info, void *context) {
      if(signal_num==SIGINT){
        printf("Caught SIGINT: Interrupt signal (Ctrl+C)\n");
        exit(0);  // Exit the program cleanly
      }
}
int main() {
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;     
    sa.sa_sigaction = signal_handler;  
    sigaction(SIGINT, &sa, NULL);
    while (1) {
        printf("Running... Press Ctrl+C to trigger SIGINT\n");
        sleep(2);
    }
    return 0;
}
/* SAMPLE OUTPUT
Running... Press Ctrl+C to trigger SIGINT
^CCaught SIGINT: Interrupt signal (Ctrl+C)
*/
