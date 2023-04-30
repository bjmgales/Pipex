/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:00:30 by bgales            #+#    #+#             */
/*   Updated: 2022/06/11 10:38:26 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_and_exit(char *str)
{
	ft_printf("%s", str);
	exit (0);
}

void	child_one(t_line arg, int *pipe_fd)
{
	int		fork_id;

	fork_id = fork();
	if (!fork_id)
	{
		close (pipe_fd[0]);
		execve(arg.path, arg.cmd, NULL);
	}
	else
	{
		close (pipe_fd[1]);
		wait(NULL);
	}
}

void	child_two(t_line arg, int *pipe_fd)
{
	int		fork_id;

	pipe(pipe_fd);
	fork_id = fork();
	if (!fork_id)
	{
		close(pipe_fd[0]);
		execve(arg.path, arg.cmd, NULL);
	}
	else
	{
		close (pipe_fd[1]);
		wait(NULL);
	}
}
