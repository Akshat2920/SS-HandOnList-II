/*
============================================================================
Name : q27.c
Author : Akshat Abhishek Lal
Description : Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag
Date: 22th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

struct m {
  long msg_type;
  char msg_data[100];
};
int main() {
  struct m msg;
  key_t key = ftok(".", 'a');
  if (key < 0)
    perror("ftok");
  int msgid = msgget(key, 0666);
  printf("Recieving msg with 0 as flag\n");
  msgrcv(msgid, &msg, sizeof(msg.msg_data), 0, 0);
  printf("recieved:%s\n", msg.msg_data);

  printf("recieving msg with IPC_NOWAIT as a flag:\n");
  msgrcv(msgid, &msg, sizeof(msg.msg_data), 0, IPC_NOWAIT);
  printf("recieved:%s\n", msg.msg_data);
}

/*Recieving msg with 0 as flag
recieved:This is message
recieving msg with IPC_NOWAIT as a flag:
recieved:This is message

 */
