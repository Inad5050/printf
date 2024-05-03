/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:13:13 by dangonz3          #+#    #+#             */
/*   Updated: 2024/05/03 13:23:46 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* characters c */

int	print_c(char arg)
{
	if (arg == 0)
		return (1);
	write(1, &arg, 1);
	return (1);
}

/* integers i & d & u */

int	print_d(int arg, char format)
{
	int	count;

	count = 0;
	if (format == 'd' || format == 'i')
		count = putnbr_alt(arg, count);
	if (format == 'u')
		count = putnbr_alt_u(arg, count);
	return (count);
}

/* hexadecimal integers x & p (lowercase) and X (uppercase) */

int	print_x(size_t arg, char format, int count)
{
	if (arg >= 16)
		count = print_x(arg / 16, format, count);
	if ((format == 'x') || (format == 'p'))
		count += print_c("0123456789abcdef"[arg % 16]);
	if (format == 'X')
		count += print_c("0123456789ABCDEF"[arg % 16]);
	return (count);
}

/* strings s */

int	print_s(char *arg)
{
	int		i;

	i = 0;
	if (!arg)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (arg[i])
	{
		write(1, &arg[i], 1);
		i++;
	}
	return (i);
}
