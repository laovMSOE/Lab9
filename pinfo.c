/******************
Name: Vian Lao
Assignment: Lab 9
Section #: 
******************/

#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>

int main(void)
{
    pid_t my_pid = getpid();
    pid_t parent_pid = getppid();

    if(my_pid != NULL){

        printf("Current Process ID: %d\n", my_pid);
        printf("Parent Process ID: %d\n", parent_pid);


        int priority = getpriority(PRIO_PROCESS, my_pid);

        printf("Priority Value: %d\n", priority);


        int policy = sched_getscheduler(my_pid); //get policy for calling process
        if (policy == -1)
        {
            perror("sched_getscheduler");
        }

        printf("Scheduling Method: ");
        switch (policy) 
        {
            case SCHED_BATCH:
                printf("SCHED_BATCH\n");
                break;
            case SCHED_OTHER:
                printf("SCHED_OTHER\n");
                break;
            case SCHED_IDLE:
                printf("SCHED_IDLE\n");
                break;
            case SCHED_FIFO:
                printf("SCHED_FIFO\n");
                break;
            case SCHED_RR:
                printf("SCHED_RR\n");
                break;
            default:
                printf("Unknown policy (%d)\n", policy);
                break;
        }

    }

    return 0;
}

