#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    int pid;

    pid = fork();

    if(pid == 0)
    {
        char **command = ft_split(argv[2], ' ');
        char *path = validate_path(envp, command[0]);
        printf("%s \n", path);

        access(ls, X_OK | F_OK)
        int fd_in = open(argv[1], O_RDONLY);
        dup2(fd_in, 0);

        

        execve(path, command, envp);

    }
    (void)argc;



    return 0;
}