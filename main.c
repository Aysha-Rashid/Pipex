/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:20:41 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/01/04 12:09:59 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int		pipe_fd[2];

	if (argc == 5)
	{
		init(&data, argv);
		if (pipe(pipe_fd) == -1)
		{
			close(pipe_fd[1]);
			close(pipe_fd[0]);
			error_close_fd(data, pipe_fd);
			exit (1);
		}
		data.pid_1 = fork();
		pid_error(data.pid_1, data.infile);
		if (data.pid_1 == 0)
			child_process(data, env, pipe_fd);
		data.pid_2 = fork();
		pid_error(data.pid_2, data.outfile);
		if (data.pid_2 == 0)
			another_child_process(data, env, pipe_fd);
		parent_process(data, pipe_fd);
	}
	else
		arg_error();
}
