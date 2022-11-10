#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//this program uses sigprocmask to block sigint and sigquit, output a loop of 1-5 with a 1 second interval before unblocking sigint and sigquit.
//then the program does the same but instead of using SIGINT and SIGQUIT, it is just SIGINT.

int main(){
sigset_t set;
sigset_t set2;
sigemptyset (&set);
sigaddset (&set, SIGINT); 
sigaddset(&set,SIGQUIT);
//sigint and sigquit are blocked.
puts("SIGINT and SIGQUIT are blocked.");
sigprocmask(SIG_BLOCK, &set, &set2);
//loop 1
for(int i = 1; i <= 5; i++){
    printf("%d\n",i);
    sleep(1);
}
//sigint and sigquit are unblocked.
puts("\nSIGINT and SIGQUIT are unblocked.");
sigprocmask(SIG_SETMASK, &set2, NULL);
//emptys signal sets
sigemptyset(&set);
sigemptyset(&set2);
sigaddset(&set,SIGINT);
//sigint is blocked.
puts("SIGINT is blocked.");
sigprocmask(SIG_BLOCK, &set, &set2);
//loop 2
for(int i = 1; i <= 5; i++){
    printf("%d\n",i);
    sleep(1);
}
//sigint is unblocked.
puts("\nSIGINT is unblocked.");
sigprocmask(SIG_SETMASK, &set2, NULL);
//uses sleep to make sure SIGINT was unblocked. 
sleep(4);
exit(0);

}
