/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggulteki <ggulteki@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:20:16 by ggulteki          #+#    #+#             */
/*   Updated: 2023/02/27 19:57:31 by ggulteki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*j1;
	unsigned char	*j2;
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	j1 = (unsigned char *)s1;
	j2 = (unsigned char *)s2;
	while (n > 0 && (j1 && j2) && i < n - 1)
	{
		if (*(unsigned char *)j1 == *(unsigned char *)j2)
		{
			j1++;
			j2++;
			i++;
		}
		else
			break ;
	}
	return (*(unsigned char *)j1 - *(unsigned char *)j2);
}
