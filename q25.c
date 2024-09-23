/*
============================================================================
Name : q25.c
Author : Akshat Abhishek Lal
Description :  Write a program to print a message queue's (use msqid_ds and ipc_perm
structures) a. access permission b. uid, gid c. time of last message sent and
received d. time of last change in the message queue d. size of the queue f.
number of messages in the queue g. maximum number of bytes allowed h. pid of the
msgsnd and msgrcv
Date: 22th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  key_t key = ftok(".", 'a');
  if (key < 0)
    perror("ftok");

  int msgid = msgget(key, 0666 | IPC_CREAT);
  struct msqid_ds msg_info;
  int out = msgctl(msgid, IPC_STAT, &msg_info);
  if (out < 0)
    perror("msgctl");
  printf("access permissions: %o\n", msg_info.msg_perm.mode);
  printf("owner UID: %d\n", msg_info.msg_perm.uid);
  printf("owner GID: %d\n", msg_info.msg_perm.gid);
  printf("time of last message sent: %ld\n", msg_info.msg_stime);
  printf("time of last message received: %ld\n", msg_info.msg_rtime);
  printf("time of last change: %ld\n", msg_info.msg_ctime);
  printf("size of the queue: %ld bytes\n", msg_info.__msg_cbytes);
  printf("number of messages in queue: %ld\n", msg_info.msg_qnum);
  printf("maximum number of bytes allowed: %ld\n", msg_info.msg_qbytes);
  printf("PID of last message sent: %d\n", msg_info.msg_perm.__key);
  msgctl(msgid, IPC_RMID, NULL);
}

/* SAMPLE OUTPUT
access permissions: 666
owner UID: 1000
owner GID: 1000
time of last message sent: 0
time of last message received: 0
time of last change: 1726852025
size of the queue: 0 bytes
number of messages in queue: 0
maximum number of bytes allowed: 16384
PID of last message sent: 1627524284
 */
