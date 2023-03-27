/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggulteki <ggulteki@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:53:15 by ggulteki          #+#    #+#             */
/*   Updated: 2023/01/14 16:53:15 by ggulteki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static void	ft_str_reverse(char *str)
{
	size_t	len;
	size_t	i;
	char	temp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
	str[len] = 0;
}

static int	count_digit(long long n)
{
	if (n / 10 == 0)
		return (1);
	return (1 + count_digit(n / 10));
}

char	*ft_itoa(int n)
{
	char	*str;
	int		neg_true;
	size_t	len;

	neg_true = (n < 0);
	len = 0;
	str = ft_calloc(count_digit(n) + neg_true + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[len++] = '0' + ft_abs(n % 10);
		n = (n / 10);
	}
	if (neg_true)
		str[len] = '-';
	ft_str_reverse(str);
	return (str);
}
