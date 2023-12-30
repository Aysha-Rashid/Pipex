/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:00:25 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/30 20:41:06 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	arg_error(void)
{
	perror("4 arguments needed!");
	exit (1);
}

void	in_file_error(void)
{
	perror("input doesn't exist or doesnt have the permission");
	exit(0);
}
