/*
============================================================================
Name : q8b.c
Author : Akshat Abhishek Lal
Description : 8. Write a separate program using signal system call to catch the following signals.
b. SIGINT
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void signal_handler(int signal_num) {
    if(signal_num == SIGINT){
      printf("Caught SIGINT: Interrupt signal\n");
      exit(0);
    }  
}
int main() {
    signal(SIGINT, signal_handler);
    while (1) {
        pause();  
    }
    return 0;
}
/* SAMPLE OUTPUT
^CCaught SIGINT: Interrupt signal
*/
