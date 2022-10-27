#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
    system("./05_1.out");
    for (int i = 1; i <= 100; i++)
    {
        printf("%d. PID = %d [OS03_06]\n", i, getpid());
        sleep(1);
    }
    exit(0);
}