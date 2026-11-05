/******************
Name: Vian Lao
Assignment: Lab 9
Section #: 
******************/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <sys/sysinfo.h>

struct timespec
    {
        time_t tv_sec; //seconds
        long tv_nsec; //nanoseconds
    };


int main(int argc, char* argv[])
{
    struct timespec ts;
    struct utsname buffer;
    char hostname[256];
    int numprocs = get_nprocs();
    long physmem = sysconf(_SC_PHYS_PAGES);
    long mem = sysconf(_SC_PAGESIZE);

    if (clock_gettime(CLOCK_REALTIME, &ts) == 0) 
    {
        printf("Time of Day in nanoseconds: %ld\n", ts.tv_nsec);
    } else {
        perror("clock_gettime");
        return 1;
    }

    if(gethostname(hostname, sizeof(hostname)) == 0)
    {
        printf("System Network Name: %s\n", hostname);
    } else {
        perror("gethostname");
        return 1;
    }

    if(uname(&buffer) == 0) {
        printf("Operating System Name: %s\n", buffer.sysname);
        printf("Operating System Release: %s\n", buffer.release);
        printf("Operating System Version: %s\n", buffer.version);
        printf("Hardware Type: %s\n", buffer.machine);
    } else {
        perror("uname");
        return 1;
    }

    printf("Number of Processors: %d\n", numprocs);

    printf("Amount of Physical Memory in Bytes: %ld\n", physmem);
    printf("Amount of Free Memory in Bytes: %ld\n", mem);

    return 0;
}