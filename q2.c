/*
============================================================================
Name : 2.c
Author : Akshat Abhishek Lal
Description : Write a program to print the system resource limits. Use getrlimit system call.
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

void print_limit(int resource, const char *resource_name) {
    struct rlimit limit;
    if (getrlimit(resource, &limit) == 0) {
        printf("%s: Soft limit = %ld, Hard limit = %ld\n", resource_name,   (long)limit.rlim_cur, (long)limit.rlim_max);
    } else {
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }
}

int main() {
    print_limit(RLIMIT_CORE, "Core file size limit (RLIMIT_CORE)");
    print_limit(RLIMIT_CPU, "CPU time limit (RLIMIT_CPU)");
    print_limit(RLIMIT_DATA, "Data segment size limit (RLIMIT_DATA)");
    print_limit(RLIMIT_FSIZE, "File size limit (RLIMIT_FSIZE)");
    print_limit(RLIMIT_MEMLOCK, "Memory lock limit (RLIMIT_MEMLOCK)");
    print_limit(RLIMIT_NOFILE, "Max number of open files (RLIMIT_NOFILE)");
    print_limit(RLIMIT_NPROC, "Max number of processes (RLIMIT_NPROC)");
    print_limit(RLIMIT_RSS, "Max resident set size (RLIMIT_RSS)");
    print_limit(RLIMIT_STACK, "Stack size limit (RLIMIT_STACK)");

    return 0;
}

/* SAMPLE OUTPUT
Core file size limit (RLIMIT_CORE): Soft limit = 0, Hard limit = -1
CPU time limit (RLIMIT_CPU): Soft limit = -1, Hard limit = -1
Data segment size limit (RLIMIT_DATA): Soft limit = -1, Hard limit = -1
File size limit (RLIMIT_FSIZE): Soft limit = -1, Hard limit = -1
Memory lock limit (RLIMIT_MEMLOCK): Soft limit = 256385024, Hard limit = 256385024
Max number of open files (RLIMIT_NOFILE): Soft limit = 1024, Hard limit = 1048576
Max number of processes (RLIMIT_NPROC): Soft limit = 7356, Hard limit = 7356
Max resident set size (RLIMIT_RSS): Soft limit = -1, Hard limit = -1
Stack size limit (RLIMIT_STACK): Soft limit = 8388608, Hard limit = -1
*/
