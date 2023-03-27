/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggulteki <ggulteki@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:41:53 by ggulteki          #+#    #+#             */
/*   Updated: 2023/02/27 19:58:14 by ggulteki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		s1_len;
	size_t		i;
	char		*ptr;

	s1_len = ft_strlen(s1);
	i = 0;
	ptr = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!ptr)
		return (NULL);
	return (ft_memcpy(ptr, s1, (s1_len + 1)));
}
