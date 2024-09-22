/*
============================================================================
Name : q5.c
Author : Akshat Abhishek Lal
Description : Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main() {
    // a. Maximum length of the arguments to the exec family of functions
    long max_arg_length = sysconf(_SC_ARG_MAX);
    printf("Maximum length of the arguments to the exec family of functions: %ld\n", max_arg_length);
    
    // b. Maximum number of simultaneous processes per user id
    long max_processes_per_user = sysconf(_SC_CHILD_MAX);
    printf("Maximum number of simultaneous processes per user id: %ld\n", max_processes_per_user);

    // c. Number of clock ticks (jiffy) per second
    long clock_ticks_per_second = sysconf(_SC_CLK_TCK);
    printf("Number of clock ticks (jiffy) per second: %ld\n", clock_ticks_per_second);

    // d. Maximum number of open files
    long max_open_files = sysconf(_SC_OPEN_MAX);
    printf("Maximum number of open files: %ld\n", max_open_files);

    // e. Size of a page
    long page_size = sysconf(_SC_PAGE_SIZE);
    printf("Size of a page: %ld bytes\n", page_size);

    // f. Total number of pages in the physical memory
    long total_pages = sysconf(_SC_PHYS_PAGES);
    printf("Total number of pages in the physical memory: %ld\n", total_pages);

    // g. Number of currently available pages in the physical memory
    long available_pages = sysconf(_SC_AVPHYS_PAGES);
    printf("Number of currently available pages in the physical memory: %ld\n", available_pages);

    return 0;
}
/* SAMPLE OUTPUT
Maximum length of the arguments to the exec family of functions: 2097152
Maximum number of simultaneous processes per user id: 7356
Number of clock ticks (jiffy) per second: 100
Maximum number of open files: 1024
Size of a page: 4096 bytes
Total number of pages in the physical memory: 500759
Number of currently available pages in the physical memory: 15571

*/
