#include<signal.h>
#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>

//this program uses 2 child processes to use SIGUSR1 and SIGUSR2 to have the parent process perform a task using the kill() function.
int main(){
pid_t childid,pid;
if((childid = fork()) == -1){
    printf("fork error");
    exit(-1);
} else if(childid == 0){
    if((pid = fork()) == -1){
        printf("fork error");
        exit(-1);
    } else if(pid>0){ //first child
        kill(getppid(),SIGUSR1);
    } else{ //second child
        kill(getppid(),SIGUSR2);
    }
} else{ //parent
if(SIGUSR1){//uses SIGUSR1
printf("Hi Honney!\n");
}
if(SIGUSR2){//uses SIGUSR2
printf("Are you getting into trouble again?\n");
}
}
exit(0);
}
