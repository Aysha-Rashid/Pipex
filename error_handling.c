/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:01:55 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/28 19:02:15 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup2_error(void)
{
	perror("dup2 failed\n");
	exit(1);
}

void	cmd_error(void)
{
	perror("Error finding command path\n");
	exit(1);
}

void	pid_error(void)
{
	perror("Error pid\n");
	exit(1);
}

void	file_error(void)
{
	perror("Permission/error file\n");
	exit(0);
}

void	close_error(void)
{
	perror("not properly closed\n");
	exit(0);
}
