#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>


static void sighandler(int sig){
    if(sig == SIGINT){
        FILE *file = fopen("log.txt","a");
        fprintf(file,"exiting due to SIGINT\n");
        exit(0);
    }
    else if(sig == SIGUSR1){
        printf("pid of parent is %d\n",getppid());
    }
}

int main(){
    signal(SIGINT,sighandler);
    signal(SIGUSR1,sighandler);
    while(1){
        printf("my pid is: %d\n",getpid());
        sleep(1);
    }
}
