#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "libft/libft.h"

typedef struct s_most_used
{
    char **command;
    char *path;
    int fd;
}              t_most_used;

char *get_env_path(char **envp);
char *validate_path(char **envp, char *cmd);

#endif