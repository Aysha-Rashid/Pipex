/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:20:41 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/30 20:00:43 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// fork creates a child process has the same exact memory as the parent process
// each process has the copy of its own variable
// when we fork it we are going to get the same value.
// process id
//
// how are we going to use these commands;
//
// redirection: 
// pipe:  sends the output of the first execve() 
//        as input to the second execve()
// _/dup: 
// _/dup2: swaps our files with stdin and stdout.
// _/access:
// _/fork:  runs two processes (i.e. two commands) 
//          in one single program
// _/execve:
// wait:
// waitpid:
// unlink:
// 
// what is not working?
// outfile permission error thats why i couldnt display things in outfile
// can't use redirection

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int		pipe_fd[2];

	if (argc == 5)
	{
		init(&data, argv);
		if ((pipe(pipe_fd)) == -1)
			exit (1);
		data.pid_1 = fork();
		if (data.pid_1 == -1)
			pid_error();
		if (data.pid_1 == 0)
			child_process(data, env, pipe_fd);
		data.pid_2 = fork();
		if (data.pid_2 == -1)
			pid_error();
		if (data.pid_2 == 0)
			another_child_process(data, env, pipe_fd);
		parent_process(data, pipe_fd);
	}
	else
		arg_error();
}
