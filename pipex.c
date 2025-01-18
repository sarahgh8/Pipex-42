#include "pipex.h"

void first_command(char **argv, char **envp, int pipe_fd[2])
{
    t_most_used v;

    v.command = ft_split(argv[2], ' ');
    v.path = validate_path(envp, v.command[0]);
    v.fd = open(argv[1], O_RDONLY);

    dup2(v.fd, STDIN_FILENO);
    dup2(pipe_fd[1], STDOUT_FILENO);

    close(pipe_fd[0]);
    close(pipe_fd[1]);
    
    execve(v.path, v.command, envp);
}

void second_command(char **argv, char **envp, int pipe_fd[2])
{
    t_most_used v;

    v.command = ft_split(argv[3], ' ');
    v.path = validate_path(envp, v.command[0]);
    v.fd = open(argv[4], O_WRONLY);

    dup2(pipe_fd[0], STDIN_FILENO);
    dup2(v.fd, STDOUT_FILENO);

    close(pipe_fd[0]);
    close(pipe_fd[1]);

    execve(v.path, v.command, envp);
}
int main(int argc, char **argv, char **envp)
{
    if(argc == 5)
    {
        int pid1;
        int pid2;
        int pipe_fd[2];

        if (pipe(pipe_fd) == -1)
        {
            perror("pipe");
            exit(1);
        }
        pid1 = fork();

        if(pid1 == 0)
            first_command(argv, envp, pipe_fd);
        pid2 = fork();
        if (pid2 == 0)
            second_command(argv, envp, pipe_fd);
    }
    else
    {
        write(2, "Error: Invalid number of arguments\n", 36);
        exit(1);
    }
    return 0;
}
