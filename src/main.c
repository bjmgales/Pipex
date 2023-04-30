/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:51:13 by bgales            #+#    #+#             */
/*   Updated: 2022/06/13 11:28:27 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>

int	pathfinder(char **str, char *to_find)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (str[++i])
	{
		while (to_find[c] == str[i][c])
			c++;
		if (!to_find[c])
			return (i);
		c = 0;
	}
	return (0);
}

void	freeing(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free (str);
}

t_line	get_exec(char *cmd, char **env)
{
	t_line	f;
	char	**paths;
	int		i;

	i = pathfinder(env, "PATH");
	if (!*env || !i)
		print_and_exit("Missing environment\n");
	paths = ft_split(env[i], ':');
	f.cmd = ft_split(cmd, ' ');
	paths[0] = ft_strtrim(paths[0], "PATH=");
	i = -1;
	while (paths[++i])
		paths[i] = ft_strjoin(ft_strjoin(paths[i], "/"), f.cmd[0]);
	i = -1;
	while (paths[++i] && access(paths[i], F_OK) == -1)
		if (!access(paths[i], F_OK))
			break ;
	if (!paths[i])
		print_and_exit("Error\nCommand not found\n");
	f.path = ft_strdup(paths[i]);
	freeing(paths);
	i = -1;
	return (f);
}

int	main(int argc, char **argv, char **env)
{
	t_line	intro;
	t_line	outro;
	int		pipe_fd[2];

	if (argc != 5)
		print_and_exit("Error\nArgument number is invalid\n");
	if (open (argv[1], O_DIRECTORY) != -1)
		print_and_exit("Error\nFD is a directory\n");
	intro = get_exec(argv[2], env);
	outro = get_exec(argv[3], env);
	intro.fd = open (argv[1], O_RDONLY | O_CLOEXEC);
	outro.fd = open (argv[4], O_RDWR | O_CREAT | O_TRUNC | O_CLOEXEC, 0644);
	pipe(pipe_fd);
	if (intro.fd == -1)
		print_and_exit("Error\nFD is invalid\n");
	if (outro.fd == -1)
		print_and_exit("Error\nOutfile is a directory\n");
	dup2(intro.fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	child_one(intro, pipe_fd);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(outro.fd, STDOUT_FILENO);
	child_two(outro, pipe_fd);
}
