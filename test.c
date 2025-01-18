#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    int fds[2];
    int pid;

    pipe(fds);
    pid = fork();

    if(pid == 0)
    {
        char *path = validate_path(envp, argv[1]);
        printf("%s \n", path);

    }
    (void)argc;



    return 0;
}