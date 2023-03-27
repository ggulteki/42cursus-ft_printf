/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggulteki <ggulteki@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:47:37 by ggulteki          #+#    #+#             */
/*   Updated: 2023/02/27 19:57:27 by ggulteki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*j;
	size_t			i;

	i = 0;
	j = (unsigned char *)s;
	while (i < n)
	{
		if (*j == (unsigned char)c)
			return ((unsigned char *)j);
		j++;
		i++;
	}
	return (NULL);
}
