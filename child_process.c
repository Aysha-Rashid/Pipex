/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:20:17 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/27 20:07:17 by ayal-ras         ###   ########.fr       */
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
    char	*cmd_path = NULL;
    int	i = 0;

    if (!cmd)
        return (NULL);
    while (env_path[i])
	{
        cmd_path = ft_strjoin(env_path[i], "/");
        char *temp = ft_strjoin(cmd_path, cmd);
        free(cmd_path);
        if (access(temp, F_OK | X_OK) == 0) {
            free(cmd_path); // Free cmd_path before returning temp
            return (temp);
        }
        free(temp); // Free temp when access check fails
        i++;
    }
    return (NULL);
}


char	**find_paths_and_split(char **envp) {
    char	*envp_path = NULL;
    char	**paths = NULL;
    int	i = 0;

    while (envp[i])
	{
        if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
            envp_path = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
            break;
        }
        i++;
    }
    if (envp_path)
	{
        paths = ft_split(envp_path, ':');
        free(envp_path); // Free allocated envp_path
    }
    return (paths);
}

char	**paths_add_slash(char **paths)
{
    int	i = 0;

    while (paths[i])
	{
        char *temp = ft_strjoin(paths[i], "/");
        free(paths[i]); // Free the original string
        paths[i] = temp; // Assign the modified string
        i++;
    }
    return (paths);
}
