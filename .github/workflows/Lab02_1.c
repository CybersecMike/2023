/*
Lab02_1
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
    {
    pid_t pid;
    int status;

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
            printf("This is the child process: PID=%d\n", getpid());
            sleep(3);
            printf("Hello world from the child process \n");
            break;

        default:
            printf("This is the parent process: PID=%d \n", getpid());
            pid = waitpid(pid, &status, 0);
            if (pid > 0) {
                printf("Child process (PID=%d) has terminated. \n", pid);
            } else {
                fprintf(stderr, "Error waiting for the child process. \n");
            }
            break;
     }

    // Both parent and child continue executing from here
    printf("Common code: PID=%d\n", getpid());

    return 0;

    }
