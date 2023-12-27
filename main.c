/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:20:41 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/27 19:50:39 by ayal-ras         ###   ########.fr       */
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

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	pid_t	pid;
	t_data	data;
	int		pipe_fd[2]; //pipe

	if (argc == 5)
	{
		init(&data, argv);
		pipe(pipe_fd);
		data.pid_1 = fork();
		if (data.pid_1 == 0)
			child_process(data, env, pipe_fd);
		data.pid_1 = fork();
		if (data.pid_2 == 0)
			another_child_process(data, env, pipe_fd);
			// parent_process(pipe_fd[0]);
		waitpid(pid, &data.status, 0); // return the process ID of the termination process
		// status is going to hold the exit status of the child process and this
		// is useful to know for the parent as they will know when to stop waiting
	}
	else
	{
		ft_printf("4 arguments needed!\n");
		return (0);
	}
}

// - Inside the pipe, everything goes to one of its ends, 
//   one end will write and the other will read (more on this in section 4).
// - end[1] is the child process, and end[0] the parent process: the child writes, 
//   while the parent reads. And since for something to be read, it must be written first,
//   so cmd1 will be executed by the child, and cmd2 by the parent.
// - For the child process, we want infile to be our stdin (we want it as input), 
// 	 and end[1] to be our stdout (we want to write to end[1] the output of cmd1).
// - In the parent process, we want end[0] to be our stdin (end[0] reads from 
// 	 end[1] the output of cmd1), and outfile to be our stdout 
// 	 (we want to write to it the output of cmd2).