#include "pipex.h"

char *get_env_path(char **envp)
{
    int i;

    i = 0;
    while(envp[i])
    {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0)
            return envp[i] + 5;
        i++;
    }
    return NULL;
}

char *validate_path(char **envp, char *cmd)
{
    char *env_path = get_env_path(envp);
    char **env_paths = ft_split(env_path, ':');
    int i;

    i = 0;
    while(env_paths[i])
    {
        char *temp;

        temp = ft_strjoin(env_paths[i], "/");
        if(!temp)
        {
            free(temp);
            return NULL;
        }
        free(env_paths[i]);
        env_paths[i] = ft_strjoin(temp, cmd);
        free(temp);
        if(!access(env_paths[i], F_OK))
        {
            if(!access(env_paths[i], R_OK | X_OK))
                return env_paths[i];
            // perror("");
            return NULL; // Permission denied
        }
        i++;
    }
    return NULL; // Command not found
}
