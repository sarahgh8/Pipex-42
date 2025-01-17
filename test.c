#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
    int process_id = fork();

    if (process_id == 0)
        printf("this is the child process\n");
    if (process_id > 0)
    {
        printf("this is parent\n");
    }

    return 0;
}