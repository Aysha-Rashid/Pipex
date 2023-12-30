/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:13:33 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/30 18:14:23 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*cmd_file(char	*cmd, char **paths)
{
	char	*cmd_file;
	int		i;

	if (!cmd)
		return (NULL);
	i = 0;
	while (cmd[i++])
	{
		if (cmd[i] == '/')
		{
			if (access(cmd, F_OK | X_OK) == 0)
				return (cmd);
			return (NULL);
		}
	}
	paths = paths_add_slash(paths);
	i = -1;
	while (paths[++i])
	{
		cmd_file = ft_strjoin(paths[i], cmd);
		if (access(cmd_file, F_OK | X_OK) == 0)
			return (cmd_file);
		free(cmd_file);
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
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			envp_path = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
			break ;
		}
		i++;
	}
	paths = ft_split(envp_path, ':');
	if (envp_path)
		free(envp_path);
	return (paths);
}

char	**paths_add_slash(char **env)
{
	int		i;
	char	**paths;

	paths = find_paths_and_split(env);
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		i++;
	}
	return (paths);
}
