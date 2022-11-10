#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <dirent.h>
#include <sys/wait.h>

//this program opens a file descriptor and outputs a child process's output into the file, and then when it comes to the parent's turn, 
//it reads from the file descriptor and outputs the file to standard output.

int main(){
umask(0);
pid_t pid;
char b[1];
int stat_val;
pid_t child_pid;
char a[13] = "My son said ";
int size,size2 = 0;
int fd1 = 0;
int nread = 0;
char *e;
fd1 = open("foo",O_CREAT | O_RDWR,0666);
pid = fork();
switch(pid){
case -1:
    printf("fork failure\n");
    exit(-1);
case 0:
//parent
    child_pid = wait(&stat_val);
    lseek(fd1,0,SEEK_SET);
    //finds size
    while(nread = read(fd1,b,1)){
        size++;
    }
    //goes back to the start
    lseek(fd1,0,SEEK_SET);
    //array e now is the size of the file + 13
    e = realloc(e,(size+13)*sizeof(char));
    //first part of e is the string a
    for(int i = 0; i < 13; i++){
        e[i] = a[i];
    }
    //second part of e is each part of the file.
    while(nread = read(fd1,b,1)){
        e[size2+13] = *b;
        size2++;
    }
    //outputs e to standard output.
    write(1,e,size+13);
    printf("\n");
    break;
default:
//child
    write(fd1,"hi, Mom\n",9);
    break;
}


exit(0);
}
