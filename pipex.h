/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:33:14 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/30 21:50:56 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>

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
void	parent_process(t_data data, int *pipe_fd);
char	**ft_cmd(char *s);
char	*cmd_file(char *cmd, char **env_path);
char	**paths_add_slash(char **env);
char	**find_paths_and_split(char **envp);
void	dup2_error(void);
void	pid_error(void);
void	file_error(void);
void	arg_error(void);
void	close_error(void);
void	ft_cmd_not_found(char *path_cmd);
void	in_file_error(void);