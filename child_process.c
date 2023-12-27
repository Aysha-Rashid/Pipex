/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:20:17 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/27 19:59:39 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_data data, char **env, int *pipe_fd)
{
	dup2(pipe_fd[1], STDOUT_FILENO);
	dup2(data.infile, STDIN_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	data.cmd_path1 = cmd_path(data.cmd1[0], env);
	execve(data.cmd_path1, data.cmd1, NULL);
}

void	another_child_process(t_data data, char **env, int *pipe_fd)
{
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(data.outfile, STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	data.cmd_path2 = cmd_path(data.cmd2[0], env);
	execve(data.cmd_path2, data.cmd2, NULL);
}

char	*cmd_path(char *cmd, char **env_path)
{
	char	*cmd_path;
	int		i;

	if (!cmd)
		return (NULL);
	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == '/')
		{
			if (access(cmd, F_OK | X_OK) == 0)
				return (cmd);
			return (NULL);
		}
	}
	env_path = paths_add_slash(env_path);
	i = -1;
	while (env_path[++i])
	{
		cmd_path = ft_strjoin(env_path[i], cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	return (NULL);
}

char	**find_paths_and_split(char **envp)
{
	char	*envp_path;
	char	**paths;
	int		i;

	if (!envp)
		return (NULL);
	envp_path = NULL;
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			envp_path = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
			break ;
		}
	}
	paths = ft_split(envp_path, ':');
	if (envp_path)
		free(envp_path);
	return (paths);
}

char	**paths_add_slash(char **paths)
{
	int		i;

	paths = find_paths_and_split(paths);
	i = -1;
	while (paths[++i])
		paths[i] = ft_strjoin(paths[i], "/");
	return (paths);
}
