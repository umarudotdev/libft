/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:02:07 by martins           #+#    #+#             */
/*   Updated: 2024/12/27 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf_internal.h"

/**
 * @brief Writes the output according to a format string.
 *
 * Supports the following conversions: c s p d i u x X %
 * Supports the following flags: - 0 . # + (space)
 * Supports field minimum width.
 *
 * @param format The format string.
 * @return The number of bytes printed. A negative value if an output error is
 * encountered.
 */
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_pf	pf;

	if (!format)
		return (-1);
	va_start(ap, format);
	ft_pf_init(&pf, 1);
	while (*format)
	{
		if (*format == '%')
		{
			if (!ft_pf_parse(&format, &pf))
				break ;
			ft_pf_dispatch(&pf, ap);
		}
		else
			ft_pf_putchar(&pf, *format++);
	}
	va_end(ap);
	return (pf.len);
}
