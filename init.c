/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:20:11 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/28 18:29:38 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init(t_data *data, char **argv)
{
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile == -1)
		file_error();
	data->cmd1 = ft_cmd(argv[2]);
	data->cmd2 = ft_cmd(argv[3]);
	data->outfile = open(argv[4], O_WRONLY | O_CREAT, S_IRUSR);
	if (data->outfile == -1)
		file_error();
}

char	**ft_cmd(char *s)
{
	if (!s)
		return (NULL);
	return (ft_split(s, ' '));
}