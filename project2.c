#include<stdio.h>
#include<time.h>
#include<sys/types.h>
#include<unistd.h>
#define _XOPEN_SOURCE 600


int main(){
    time_t seconds;
    seconds = time(NULL);
    int p;
    p=fork();
    printf("START: %ld\n", seconds);
    printf("PPID: %d, PID: %d\n", getppid(), getpid());

    return 1;
}

