/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:20:17 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/28 19:02:11 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_data data, char **env, int *pipe_fd)
{
	dup2(data.infile, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	if (dup2(data.infile, STDIN_FILENO) == -1)
		dup2_error();
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		dup2_error();
	data.cmd_path1 = cmd_path(data.cmd1[0], env);
	if (data.cmd_path1 == NULL)
		cmd_error();
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execve(data.cmd_path1, data.cmd1, NULL);
	perror("execve failed");
	exit(0);
}

void	another_child_process(t_data data, char **env, int *pipe_fd)
{
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(data.outfile, STDOUT_FILENO);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		dup2_error();
	if (dup2(data.outfile, STDOUT_FILENO) == -1)
		dup2_error();
	data.cmd_path2 = cmd_path(data.cmd2[0], env);
	if (data.cmd_path2 == NULL)
		cmd_error();
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execve(data.cmd_path2, data.cmd2, NULL);
	perror("execve failed");
	exit(0);
}

void	parent_process(t_data data, char **env, int *pipe_fd)
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(data.infile);
	if (close(data.infile) == -1)
		close_error();
	close(data.outfile);
	if (close(data.outfile) == -1)
		close_error();
	waitpid(data.pid_1, &data.status, 0);
	waitpid(data.pid_2, &data.status1, 0);
}
