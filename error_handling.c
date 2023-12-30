/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:01:55 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/30 20:41:20 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup2_error(void)
{
	perror("dup2 failed");
	exit(1);
}

void	pid_error(void)
{
	perror("Error pid");
	exit(1);
}

void	file_error(void)
{
	perror("Permission/error file");
	exit(1);
}

void	close_error(void)
{
	perror("not properly closed");
	exit(1);
}

void	ft_cmd_not_found(char *path_cmd)
{
	if (!path_cmd)
	{
		perror("Command not found");
		exit(1);
	}
}
