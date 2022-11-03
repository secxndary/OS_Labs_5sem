#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define _GNU_SOURCE
/*  Info about threads:   ps -Lp <PID> H  
                          ps -fL -p <PID> H
*/


int main()
{
    pid_t pid = getpid();
    pid_t tid = gettid();
    for (short i = 1; i <= 10000; ++i)
    {
        printf("%d. PID = %d     TID = %d\n", i, pid, tid);
        sleep(1);
    }
    exit(0);
}