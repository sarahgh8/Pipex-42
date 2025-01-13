#include <stdio.h>
#include <unistd.h>

int main()
{
    int id = fork();

    if(id == 0)
        printf("Child process\n");
    else
        printf("Parent process\n");
    printf("pid: %d\n", getpid());
    printf("ppid: %d\n", getppid());



    return 0;
}