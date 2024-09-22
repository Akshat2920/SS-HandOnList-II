/*
============================================================================
Name : q10a.c
Author : Akshat Abhishek Lal
Description : Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signal_num, siginfo_t *info, void *context) {
      if(signal_num==SIGSEGV){
        printf("Caught SIGSEGV: Segmentation fault occurred\n");
        exit(1);
      }
}
int main() {
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;     
    sa.sa_sigaction = signal_handler;  
    sigaction(SIGSEGV, &sa, NULL);
    int *ptr = NULL;
    *ptr = 1;
    while (1) {
        pause();
    }

    return 0;
}
/* SAMPLE OUTPUT
Caught SIGSEGV: Segmentation fault occurred
*/
