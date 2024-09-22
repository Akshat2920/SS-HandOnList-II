/*
============================================================================
Name : q8f.c
Author : Akshat Abhishek Lal
Description : 8. Write a separate program using signal system call to catch the following signals.
f. SIGVTALRM (use setitimer system call)
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void signal_handler(int signal_num) {
    if(signal_num == SIGVTALRM)
        printf("Caught SIGVTALRM: Virtual timer alarm\n");
}

int main() {
    signal(SIGVTALRM, signal_handler);
    struct itimerval timer_virtual;
    timer_virtual.it_value.tv_sec = 3;   // First alarm after 4 seconds
    timer_virtual.it_value.tv_usec = 0;
    timer_virtual.it_interval.tv_sec = 1; // No repeating
    timer_virtual.it_interval.tv_usec = 0;
    setitimer(ITIMER_VIRTUAL, &timer_virtual, NULL);
    while (1) {
        for(int i=0; i<10000; i++){} 
    }
    return 0;
}
/* SAMPLE OUTPUT
Caught SIGVTALRM: Virtual timer alarm
Caught SIGVTALRM: Virtual timer alarm
Caught SIGVTALRM: Virtual timer alarm
*/
