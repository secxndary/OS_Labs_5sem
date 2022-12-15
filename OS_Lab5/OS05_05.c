#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sched.h>

int main()
{
    pid_t pid = getpid();
    pid_t tid = gettid();
    int nicity = nice(-20);

    for (int i = 0; i < 10000; ++i)
    {
        printf("PID:  %d\nTID:  %d\nNice: %d\n\n", pid, tid, nicity);
        sleep(1);
    }
}