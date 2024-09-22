/*
============================================================================
Name : q10c.c
Author : Akshat Abhishek Lal
Description : Write a separate program using sigaction system call to catch the following signals.
c. SIGFPE
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signal_num, siginfo_t *info, void *context) {
      if(signal_num==SIGFPE){
        printf("Caught SIGFPE: Floating point exception (division by zero)\n");
        exit(1); 
      }
}
int main() {
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;     
    sa.sa_sigaction = signal_handler;  
    sigaction(SIGFPE, &sa, NULL);
    int a = 0;
    int b = 1/a;
    while(1){
      pause();
    }
    return 0;
}
/* SAMPLE OUTPUT
Caught SIGFPE: Floating point exception (division by zero)
*/
