/*
============================================================================
Name : q24.c
Author : Akshat Abhishek Lal
Description :  Write a program to create a message queue and print the key and message 
queue ID
Date: 22th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(void) {
  int key = ftok(".", 'b');
  int msgid = msgget(key, IPC_CREAT | 0744);
  printf("Key: %d  ,  Message Queue ID: %d \n", key, msgid);
  return 0;
}

/* SAMPLE OUTPUT
Key: 1644301500  ,  Message Queue ID: 0
*/