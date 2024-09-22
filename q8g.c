/*
============================================================================
Name : q8g.c
Author : Akshat Abhishek Lal
Description : 8. Write a separate program using signal system call to catch the following signals.
g. SIGPROF (use setitimer system call)
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void signal_handler(int signal_num) {
    if(signal_num == SIGPROF)
        printf("Caught SIGPROF: Profiling timer alarm\n");    
}
int main() {
    signal(SIGPROF, signal_handler);
    
    struct itimerval timer_prof;
    timer_prof.it_value.tv_sec = 3;     
    timer_prof.it_value.tv_usec = 0;
    timer_prof.it_interval.tv_sec = 1;  
    timer_prof.it_interval.tv_usec = 0;
    setitimer(ITIMER_PROF, &timer_prof, NULL);
    while (1) {
        for(int i=0; i<1000; i++){}
    }
    return 0;
}
/* SAMPLE OUTPUT
Caught SIGPROF: Profiling timer alarm
Caught SIGPROF: Profiling timer alarm
Caught SIGPROF: Profiling timer alarm
*/
