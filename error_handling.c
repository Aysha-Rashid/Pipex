/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:01:55 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/01/04 15:35:11 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup2_error(int files, int pipe_fd)
{
	if (pipe_fd == -1 || files == -1)
	{
		close(pipe_fd);
		close(files);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
		exit(1);
	}
}

void	pid_error(int pid, int files)
{
	if (pid == -1)
	{
		close(files);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
	}
}

void	file_error(int files)
{
	if (files == -1)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
		exit(1);
	}
}

void	close_error(void)
{
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	exit(1);
}

void	ft_cmd_not_found(char *path_cmd, t_data data)
{
	if (!path_cmd)
	{
		free(path_cmd);
		free_path(data.cmd1);
		free_path(data.cmd2);
		write(2, "Command not found\n", 19);
		exit(1);
	}
}
