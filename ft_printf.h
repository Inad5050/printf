/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:51:41 by dangonz3          #+#    #+#             */
/*   Updated: 2024/05/03 13:31:22 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

/* ft_printf */

int		ft_printf(char const *s, ...);
int		selection(char const *s, int i, va_list args);

/* auxiliars */

int		putnbr_alt(int n, int count);
int		putnbr_alt_u(unsigned int n, int count);

/* printer */

int		print_d(int arg, char format);
int		print_x(size_t arg, char format, int count);
int		print_s(char *arg);
int		print_c(char arg);

#endif
