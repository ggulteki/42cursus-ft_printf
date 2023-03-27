/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggulteki <ggulteki@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:31:29 by ggulteki          #+#    #+#             */
/*   Updated: 2023/03/13 19:58:36 by ggulteki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int d)
{
	int	out;

	out = 0;
	if (d >= 10)
		out += ft_unsigned(d / 10);
	write(1, &"0123456789"[d % 10], 1);
	return (out + 1);
}

int	ft_int(int i)
{
	char	*src;
	int		out;

	src = ft_itoa(i);
	out = ft_strlen(src);
	ft_putstr_fd(src, 1);
	free(src);
	return (out);
}

int	ft_hex(unsigned int i, char c)
{
	int		out;

	out = 0;
	if (i >= 16)
		out += ft_hex(i / 16, c);
	if (c == 'X')
		write(1, &"0123456789ABCDEF"[i % 16], 1);
	if (c == 'x')
		write(1, &"0123456789abcdef"[i % 16], 1);
	return (out + 1);
}

int	ft_point(unsigned long a, int sign)
{
	int		out;

	out = 0;
	if (sign == 1)
	{
		out += write(1, "0x", 2);
		sign = 0;
	}
	if (a >= 16)
		out += ft_point(a / 16, 0);
	write(1, &"0123456789abcdef"[a % 16], 1);
	return (out + 1);
}

int	ft_string(char *str)
{
	int		i;

	i = -1;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}
