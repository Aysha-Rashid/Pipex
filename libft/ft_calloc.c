/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:30:22 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/24 19:43:34 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t	count, size_t	size)
{
	char	*ptr;

	if (size != 0 && count > UINT32_MAX / size)
		return (NULL);
	ptr = malloc (count * size);
	if (ptr == 0)
	{
		return (ptr);
	}
	ft_bzero (ptr, count * size);
	return (ptr);
}
