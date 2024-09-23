/*
============================================================================
Name : q28.c
Author : Akshat Abhishek Lal
Description : Write a program to remove the message queue.
Date: 22th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <time.h>

int main() {
  // create a new message queue
  int key = ftok(".", 'b');
  int qid = msgget(key, IPC_CREAT | 0666);
  if (qid == -1) {
    perror("MSGGET ERROR");
    return -1;
  }
  printf("Message queue ID: %d\n", qid);

  struct msqid_ds qinfo;

  // Get current permission of queue
  int ret = msgctl(qid, IPC_STAT,
                   &qinfo); // to perform control operations on message queue
  if (ret == -1) {
    perror("MSGCTL ERROR");
    return -1;
  } else {
    printf("Current permission of the queue : 0%o\n", qinfo.msg_perm.mode);
  }

  // Set the permission of queue
  qinfo.msg_perm.mode = 436; // 0664 in octal
  msgctl(qid, IPC_SET, &qinfo);

  // Retrieve modified permission
  int ret1 = msgctl(qid, IPC_STAT,
                    &qinfo); // to perform control operations on message queue
  if (ret1 == -1) {
    perror("MSGCTL ERROR");
    return -1;
  } else {
    printf("Modified permission of the queue : 0%o\n", qinfo.msg_perm.mode);
  }
  return 0;
}

// OUTPUT
// Message queue ID: 2
// Current permission of the queue : 0666
// Modified permission of the queue : 0664
