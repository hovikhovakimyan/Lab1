#include<stdio.h>
#include<time.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include <sys/times.h>

int main(){
    int firstpid = getpid();
    struct tms *tms;
    times(tms);
    printf("START: %ld\n", time(NULL));
    int p;
    p=fork();
    if(getpid()==firstpid){
        printf("PPID: %d, PID: %d, CPID: %d, RETVAL: %d\n", getppid(), getpid(), p, wait(NULL));
        printf("USER: %ld, SYS: %ld\n",tms->tms_utime, tms->tms_stime);
        printf("CUSER: %ld, CSYS: %ld\n",tms->tms_cutime, tms->tms_cstime);
        printf("Exit: %ld",time(NULL));
    }
    else{
    printf("PPID: %d, PID: %d\n", getppid(), getpid());
    }
    return 1;
}

