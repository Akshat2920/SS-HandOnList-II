/*
============================================================================
Name : q22.c
Author : Akshat Abhishek Lal
Description :  Write a program to wait for data to be written into FIFO within 10
seconds, use select system call with FIFO.
Date: 22th Sep, 2024.
============================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>

int main(void) {
  int fd, retval;
  char buf[80];
  fd_set rfds;
  struct timeval tv;

  fd = open("special_fifo", O_RDONLY);
  FD_ZERO(&rfds);
  FD_SET(fd, &rfds);

  tv.tv_sec = 5;
  tv.tv_usec = 0;

  retval = select(fd + 1, &rfds, NULL, NULL, &tv);
  if (retval) {
    printf("Data Available!!\n");
  } else {
    printf("Data Not Available in 5 seconds.\n");
    return 0;
  }
  read(fd, buf, sizeof(buf));
  printf("Text from FIFO: %s\n", buf);
  return 0;
}


/* SAMPLE OUTPUT
Data Available!!
Text from FIFO: hello
*/