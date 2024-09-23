/*
============================================================================
Name : q26.c
Author : Akshat Abhishek Lal
Description : Write a program to send messages to the message queue. Check $ipcs -q
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

struct msg {
  long msg_type;
  char msg_data[100];
};

int main() {
  struct msg message;
  key_t key = ftok(".", 'a');

  int msgid = msgget(key, 0666 | IPC_CREAT);
  message.msg_type = 1;
  snprintf(message.msg_data, sizeof(message.msg_data), "This is message");
  msgsnd(msgid, &message, sizeof(message.msg_data), 0);
}
