/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggulteki <ggulteki@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:37:57 by ggulteki          #+#    #+#             */
/*   Updated: 2023/03/24 19:06:19 by ggulteki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

bool	ft_fmt_specifier(const char *str, int i)
{
	return (str[i + 1] == 'c' || str[i + 1] == 'd' || str[i + 1] == 'i'
		|| str[i + 1] == 'u' || str[i + 1] == 'x'
		|| str[i + 1] == 'X' || str[i + 1] == 'p' || str[i + 1] == 's');
}

int	ft_selector(va_list args, char c)
{
	if (c == 'u')
		return (ft_unsigned(va_arg((args), unsigned int)));
	else if (c == 'c')
		return (ft_putchar(va_arg((args), int)));
	else if (c == 'i' || c == 'd')
		return (ft_int(va_arg((args), int)));
	else if (c == 'x' || c == 'X')
		return (ft_hex(va_arg((args), unsigned int), c));
	else if (c == 'p')
		return (ft_point(va_arg((args), unsigned long), 1));
	else if (c == 's')
		return (ft_string(va_arg((args), char *)));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		output;

	va_start(args, str);
	i = -1;
	output = 0;
	while (str[++i])
	{
		if ((str[i] == '%') && (str[i + 1] != '\0'))
		{
			if (!ft_fmt_specifier(str, i))
				output += ft_putchar(str[i + 1]);
			output += ft_selector(args, str[++i]);
		}
		else if ((str[i] == '%') && (str[i + 1] == '\0'))
			return (0);
		else
			output += write(1, &str[i], 1);
	}
	va_end(args);
	return (output);
}
