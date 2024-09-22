/*
============================================================================
Name : q8d.c
Author : Akshat Abhishek Lal
Description : 8. Write a separate program using signal system call to catch the following signals.
d. SIGALRM (use alarm system call)
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void signal_handler(int signal_num) {
    if(signal_num == SIGALRM)
        printf("Caught SIGALRM: Alarm signal\n");
}
int main() {
    signal(SIGALRM, signal_handler);
    alarm(2);  // Set an alarm for 2 seconds
    while (1) {
        pause(); 
    }

    return 0;
}
/* SAMPLE OUTPUT
Caught SIGALRM: Alarm signal
*/
