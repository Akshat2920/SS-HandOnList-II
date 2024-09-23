/*
============================================================================
Name : q19a.c
Author : Akshat Abhishek Lal
Description : Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
Date: 22th Sep, 2024.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main() {
    if(mknod("myfifo", S_IFIFO | 0666, 0)==-1){
      perror("mknod system call failed");
      return 1;
    }
    else
      printf("FIFO created using mknod system call");
    return 0;
}

/* SAMPLE OUTPUT
*/
