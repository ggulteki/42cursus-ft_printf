/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggulteki <ggulteki@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:23:08 by ggulteki          #+#    #+#             */
/*   Updated: 2023/02/27 19:57:36 by ggulteki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*i;
	char	*j;

	i = (char *)dst;
	j = (char *)src;
	if (!src && !dst)
		return (0);
	while (n > 0)
	{
		*i = *j;
		i++;
		j++;
		n--;
	}
	return (dst);
}
