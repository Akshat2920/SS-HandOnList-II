/*
============================================================================
Name : q12.c
Author : Akshat Abhishek Lal
Description :  Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 22th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    if (pid == 0) {
        printf("Child process (PID: %d) is running\n", getpid());
        printf("Child sending SIGKILL to parent (PID: %d)\n", getppid());
        kill(getppid(), SIGKILL);
        printf("Parent process has been killed. Child process becomes orphan\n");
        sleep(2);
        printf("Orphan child process is now adopted by parent (PID: %d)\n", getppid());
    } else {
        printf("Parent process (PID: %d) is running\n", getpid());
        sleep(5); 
    }
    return 0;
}
/* SAMPLE OUTPUT
Parent process (PID: 16545) is running
Child process (PID: 16546) is running
Child sending SIGKILL to parent (PID: 16545)
Parent process has been killed. Child process becomes orphan
Killed
parallels@ubuntu-linux-2404:/media/psf/iCloud/Term-1/System Softwares/Hands-on List II/MT2024015$ Orphan child process is now adopted by parent (PID: 2369)
*/
