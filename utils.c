/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:25:49 by sghunmin          #+#    #+#             */
/*   Updated: 2025/01/19 15:29:21 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_env_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*validate_path(char **envp, char *cmd)
{
    t_most_used v;
	
    v.env_path = get_env_path(envp);
	if (!v.env_path)
		return (NULL);
	v.env_paths = ft_split(v.env_path, ':');
	if (!v.env_paths)
		return (NULL);
	v.i = -1;
	while (v.env_paths[++v.i])
	{
		v.temp = ft_strjoin(v.env_paths[v.i], "/");
		if (!v.temp)
		{
			free(v.temp);
			return (NULL);
		}
		free(v.env_paths[v.i]);
		v.env_paths[v.i] = ft_strjoin(v.temp, cmd);
		free(v.temp);
		if (!access(v.env_paths[v.i], F_OK))
		{
			if (!access(v.env_paths[v.i], R_OK | X_OK))
				return (v.env_paths[v.i]);
			return (NULL);
		}
	}
	return (NULL);
}

void free_2d(char **cmd)
{
    if (cmd)
    {
        int i = -1;
        while (cmd[++i])
            free(cmd[i]);
        free(cmd);
    }
}

void my_error(int *fd, t_most_used *p)
{
    perror("pipex:");
	if(fd)
	{
		close(fd[0]);
		close(fd[1]);
	}
	if(p->fd != -1)
		close(p->fd);
	if(p->command)
    	free_2d(p->command);
    if (p->path)
       free(p->path);
    if (p->env_path)
        free(p->env_path);
    if (p->env_paths)
        free_2d(p->env_paths);
    if (p->temp)
        free(p->temp);
    exit(1);
}


