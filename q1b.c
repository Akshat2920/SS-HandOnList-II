/*
============================================================================
Name : 1b.c
Author : Akshat Abhishek Lal
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
    a. ITIMER_VIRTUAL
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

struct timeval start_time;

void vtalarm_handler(int signum) {
    struct timeval current_time;
    gettimeofday(&current_time, NULL);

    long seconds = current_time.tv_sec - start_time.tv_sec ;
    long microseconds = current_time.tv_usec - start_time.tv_usec ;

    if (microseconds < 0) {
        seconds--;
        microseconds += 1000000;
    }

    printf("ITIMER_VIRTUAL signal caught! Time elapsed: %ld seconds, %ld microseconds\n", seconds, microseconds);
    gettimeofday(&start_time, NULL);
}

int main() {
    struct itimerval timer;
    gettimeofday(&start_time, NULL);
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    signal(SIGVTALRM, vtalarm_handler);
    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
        perror("Error setting ITIMER_VIRTUAL");
        exit(1);
    }

    while (1) {
        for(int i=0; i<10000; i++){i++; i--;}
    }
}

/*SAMPLE OUTPUT
ITIMER_VIRTUAL signal caught! Time elapsed: 10 seconds, 5396 microseconds
ITIMER_VIRTUAL signal caught! Time elapsed: 9 seconds, 999961 microseconds
ITIMER_VIRTUAL signal caught! Time elapsed: 9 seconds, 999969 microseconds
ITIMER_VIRTUAL signal caught! Time elapsed: 9 seconds, 999973 microseconds
*/


