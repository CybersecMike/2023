/*
Lab02_2
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
    {
    pid_t pid;

    //Create a new process using fork
    pid = fork();

    if (pid < 0) {
       fprintf(stderr, "Error: fork was unsuccessful \n");
       return 1;
    }

    switch (pid) {

        case -1:
            fprintf(stderr, "Error: fork was unsuccessful \n");
            break;

        case 0:
            printf("This is the child process: PID=%d, PPID=%d\n", getpid(), getppid());
            printf("Hello world from the child process \n");
            sleep(8); //Child process sleeps for 8 seconds
            break;

        default:
            printf("This is the parent process: PID=%d, Child PID=%d \n", getpid(), pid);
            sleep(3); //Parent process sleeps for 3 seconds
            printf("Parent process terminating \n");
            exit(0);
            break;
     }

    // child process continues executing from here
    printf("Common code: PID=%d, PPID=%d\n", getpid(), getppid());

    return 0;

    }
