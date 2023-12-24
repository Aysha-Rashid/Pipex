// fork creates a child process has the same exact memory as the parent process
// each process has the copy of its own variable
// when we fork it we are going to get the same value.
// process id
//
// dup:
// dup2:
// access:
// fork:
// pipe:
// execve:
// wait:
// waitpid:
// unlink:


#include "pipex.h"

int	main(int argc, char **argv)
{

	if (argc == 5)
		(void)argv;
	else
	{
		ft_printf("4 arguments needed!\n");
		return (0);
	}
}