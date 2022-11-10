#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

//ctrlc1.c from the book.

//function that is called by SIGINT once signal is used.
void ouch(int sig){
    printf("OUCH! - I got signal %d\n", sig);
    (void) signal(SIGINT, SIG_DFL);
}

int main(){
    (void) signal(SIGINT, ouch);

    while(1){
        printf("Hello World!\n");
        sleep(1);
    }
exit(0);
}
