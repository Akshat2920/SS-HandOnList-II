/*
============================================================================
Name : q3.c
Author : Akshat Abhishek Lal
Description : Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
   clock_t start, end;
   pid_t ppid;
   start = clock();
   for(int i=0; i<100; i++)
      ppid = getppid();
   end = clock()-start;
   double time_taken = ((double)end)/CLOCKS_PER_SEC; 
   printf("100 getppid() %f seconds to execute \n", time_taken); 
   return 0;
}
/* SAMPLE OUTPUT
100 getppid() 0.000027 seconds to execute 
*/
