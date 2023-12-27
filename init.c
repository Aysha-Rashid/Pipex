/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:20:11 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/27 20:00:51 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init(t_data *data, char **argv)
{
	data->infile = open(argv[1], O_RDONLY);
	data->cmd1 = ft_cmd(argv[2]);
	data->cmd2 = ft_cmd(argv[3]);
	data->outfile = open(argv[4], O_WRONLY | O_CREAT);
}

char	**ft_cmd(char *s)
{
	if (!s)
		return (NULL);
	return (ft_split(s, ' '));
}
