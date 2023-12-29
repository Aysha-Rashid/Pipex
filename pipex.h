/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:33:14 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/29 15:49:38 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

typedef struct s_data
{
	pid_t	pid_1;
	pid_t	pid_2;
	char	**cmd1;
	char	**cmd2;
	char	*cmd_path1;
	char	*cmd_path2;
	int		status;
	int		status1;
	int		infile;
	int		outfile;
}			t_data;

void	init(t_data *data, char **argv);
void	child_process(t_data data, char **env, int *pipe_fd);
void	another_child_process(t_data data, char **env, int *pipe_fd);
void	parent_process(t_data data, char **env, int *pipe_fd);
char	**ft_cmd(char *s);
char	*cmd_path(char *cmd, char **env_path);
char	**paths_add_slash(char **paths);
char	**find_paths_and_split(char **envp);
void	dup2_error(void);
void	pid_error(void);
void	file_error(void);
void	arg_error(void);
void	close_error(void);
void	ft_cmd_not_found(char *path_cmd, char	**cmd);
void	ft_error_handle(t_data data, int *pipe_fd);