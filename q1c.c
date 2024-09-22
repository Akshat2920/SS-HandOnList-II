/*
============================================================================
Name : 1c.c
Author : Akshat Abhishek Lal
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
    c. ITIMER_PROF
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

struct timeval start_time;

void prof_handler(int signum) {
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    long seconds = current_time.tv_sec - start_time.tv_sec;
    long microseconds = current_time.tv_usec - start_time.tv_usec;
    if (microseconds < 0) {
        seconds--;
        microseconds += 1000000;
    }
    printf("ITIMER_PROF signal caught! Time elapsed: %ld seconds, %ld microseconds\n", seconds, microseconds);
    gettimeofday(&start_time, NULL);
}

int main() {
    struct itimerval timer;
    gettimeofday(&start_time, NULL);
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    signal(SIGPROF, prof_handler);

    if (setitimer(ITIMER_PROF, &timer, NULL) == -1) {
        perror("Error setting ITIMER_PROF");
        exit(1);
    }
    while (1) {
        for (long i = 0; i < 10000; i++) {}  
    }

    return 0;
}
/*SAMPLE OUTPUT
ITIMER_PROF signal caught! Time elapsed: 10 seconds, 8125 microseconds
ITIMER_PROF signal caught! Time elapsed: 10 seconds, 33932 microseconds
ITIMER_PROF signal caught! Time elapsed: 10 seconds, 9977 microseconds
ITIMER_PROF signal caught! Time elapsed: 10 seconds, 3010 microseconds
*/


