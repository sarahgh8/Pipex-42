/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:25:29 by sghunmin          #+#    #+#             */
/*   Updated: 2025/01/19 15:30:53 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_command(char **argv, char **envp, int pipe_fd[2])
{
	t_most_used	v;

	ft_bzero(&v, sizeof(t_most_used));
	v.fd = open(argv[1], O_RDONLY);
	if(v.fd == -1)
		my_error(pipe_fd, &v);
	v.command = ft_split(argv[2], ' ');
	if(!v.command)
		my_error(pipe_fd, &v);
	v.path = validate_path(envp, v.command[0]);
	if(!v.path)
		my_error(pipe_fd, &v);
	if(dup2(v.fd, STDIN_FILENO) == -1
		|| dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		my_error(pipe_fd, &v);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(v.fd);
	if(execve(v.path, v.command, envp) == -1)
		my_error(NULL, &v);
	
}

void	second_command(char **argv, char **envp, int pipe_fd[2])
{
	t_most_used	v;

	ft_bzero(&v, sizeof(t_most_used));
	v.fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(v.fd == -1)
		my_error(pipe_fd, &v);
	v.command = ft_split(argv[3], ' ');
	if(!v.command)
		my_error(pipe_fd, &v);
	v.path = validate_path(envp, v.command[0]);
	if(!v.path)
		my_error(pipe_fd, &v);
	if(dup2(pipe_fd[0], STDIN_FILENO) == -1 ||
		dup2(v.fd, STDOUT_FILENO) == -1)
		my_error(pipe_fd, &v);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(v.fd);
	if(execve(v.path, v.command, envp) == -1)
		my_error(pipe_fd, &v);
}

int	main(int argc, char **argv, char **envp)
{
	int	pid1;
	int	pid2;
	int	pipe_fd[2];

	if (argc == 5)
	{
		if (pipe(pipe_fd) == -1)
		{
			perror("pipe");
			exit(1);
		}
		pid1 = fork();
		if (pid1 == 0)
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
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
