#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*This program is almost identical to the alarm.c program from the textbook but it uses the function sigaction*/

//global integer for the alarm
static int alarm_fired = 0;

//function that changes the global variable alarm_fired
void ding(int sig){
    alarm_fired = 1;
}

//main function
int main(){
    pid_t pid;
    printf("alarm application starting \n");
    pid = fork();
    switch(pid){
        case -1:
        printf("fork failed \n");
        exit(1);
        case 0:
            sleep(5);
            kill(getppid(),SIGALRM);
        exit(0);
    }
    struct sigaction act;
    act.sa_flags = 0;
    act.sa_handler = ding;
    printf("waiting for alarm to go off \n");
    //sigaction is used to swap SIGALRM to call the act function.
    (void) sigaction(SIGALRM,&act,0);


    pause();
    if(alarm_fired){
        printf("Ding!\n");
    }
    exit(0);


}
