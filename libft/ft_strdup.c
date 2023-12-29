/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:46:36 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/24 19:44:52 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char	*s1)
{
	int		len;
	int		i;
	char	*ptr;

	len = ft_strlen(s1);
	i = 0;
	ptr = (char *) malloc(sizeof(*ptr) * (len + 1));
	if (!ptr)
	{
		return (NULL);
	}
	if (ptr >= 0)
	{
		while (*s1)
		{
			ptr[i++] = *s1++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}
