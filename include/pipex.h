/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:58:57 by bgales            #+#    #+#             */
/*   Updated: 2023/04/30 14:20:40 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct s_line
{
	char	*path;
	char	**cmd;
	int		fd;
}	t_line;

/**
@brief Prints the given string to standard output and exits the program with
       status code 0.
 *
@param str The string to be printed.
 */
void print_and_exit(char *str);

/**
@brief Creates a child process to execute a given command and closes one end
       of a pipe.
 *
@param arg The t_line struct containing the command to be executed and its
           arguments.
@param pipe_fd An array of two file descriptors for the pipe.
 */
void child_one(t_line arg, int *pipe_fd);

/**
@brief Creates a child process to execute a given command and creates a pipe.
 *
@param arg The t_line struct containing the command to be executed and its
           arguments.
@param pipe_fd An array of two file descriptors for the pipe.
 */
void child_two(t_line arg, int *pipe_fd);

/**
@brief Finds the path of an executable file in the environment variables and
       returns a t_line struct containing the path and the arguments for the
       command.
 *
@param cmd The name of the command.
@param env The environment variables.
@return A t_line struct containing the path and arguments for the command.
 */
t_line get_exec(char *cmd, char **env);

/**
@brief Finds the index of the environment variable containing the paths for
       executables.
 *
@param str The array of environment variables.
@param to_find The string to search for.
@return The index of the environment variable containing the paths for
        executables.
 */
int pathfinder(char **str, char *to_find);

/**
@brief Frees the memory allocated for an array of strings.
 *
@param str The array of strings.
 */
void freeing(char **str);

/**

@brief The main function of the pipex program.
This function is responsible for parsing the command line arguments,
finding the executable files for the two commands specified in the
arguments, opening the input and output files, creating a pipe for
inter-process communication, and executing the two commands with
their respective file descriptors connected to the pipe. If any
error occurs during the execution, the program exits and prints
an error message.
@param argc The number of command line arguments.
@param argv An array of strings containing the command line arguments.
@param env An array of strings containing the environment variables.
@return The exit status of the program.
*/
int main(int argc, char **argv, char **env);
#endif