/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:25:41 by sghunmin          #+#    #+#             */
/*   Updated: 2025/01/19 15:25:44 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_most_used
{
	char	**command;
	char	*path;
	int		fd;
    char	*env_path;
	char	**env_paths;
	char	*temp;
	int		i;
}			t_most_used;

char		*get_env_path(char **envp);
char		*validate_path(char **envp, char *cmd);
void	my_error(int *fd, t_most_used *p);

#endif
