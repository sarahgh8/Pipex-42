#include "pipex.h"

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        int fd = open(argv[1], O_RDONLY, 0666);
        if(fd == -1)
        {
            perror("open");
            return 1;
        }
        dup2(fd, 0); // stdin is now ==> infile
        close(fd);
        int pid = fork();

        char *args[] = {"grep", "sarah", NULL};
        if(pid == 0)
        {
            execve("/bin/grep", args, NULL);
            printf("child process\n");
        }
        else
        {
            wait(NULL);
            printf("parent process\n");
        }

    }

    return 0;
}