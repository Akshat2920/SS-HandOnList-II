/*
============================================================================
Name : q8e.c
Author : Akshat Abhishek Lal
Description : 8. Write a separate program using signal system call to catch the following signals.
e. SIGALRM (use setitimer system call)
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
int main(){
    signal(SIGALRM, signal_handler);

    struct itimerval timer_real;
    timer_real.it_value.tv_sec = 3;      
    timer_real.it_value.tv_usec = 0;
    timer_real.it_interval.tv_sec = 1;  
    timer_real.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &timer_real, NULL);
    while (1) {
        pause();  
    }
    return 0;
}
/* SAMPLE OUTPUT
Caught SIGALRM: Alarm signal
Caught SIGALRM: Alarm signal
Caught SIGALRM: Alarm signal
*/
