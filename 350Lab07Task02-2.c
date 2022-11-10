#include<signal.h>
#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>

//this is ctrlc2.c, which uses sigaction to call the ouch function rather than using signal.

//function that is called by sigaction once SIGINT is used. (particularly ctrl+c)
void ouch(int sig){
    printf("OUCH! - I got signal %d\n", sig);
    struct sigaction act2;
    act2.sa_handler = SIG_DFL;
    act2.sa_flags = 0;
    //SIGINT now terminates the program.
    sigaction(sig,&act2,0);
}


int main(){
    struct sigaction act;
    act.sa_handler = ouch;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    //SIGINT now calls ouch.
    sigaction(SIGINT, &act,0);

    while(1){
        printf("Hello World!\n");
        sleep(1);
    }
exit(0);
}
