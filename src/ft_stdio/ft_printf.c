/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:02:07 by martins           #+#    #+#             */
/*   Updated: 2024/12/15 18:06:13 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include <unistd.h>

/**
 * @brief TODO: Writes the output according to a format string.
 *
 * @param format The format string.
 * @return The number of bytes printed. A negative value if an output error is
 * encountered.
 */
int	ft_printf(const char *format __attribute__((unused)), ...)
{
	ft_putstr_fd(__func__, STDERR_FILENO);
	ft_putendl_fd(" is not implemented yet", STDERR_FILENO);
	return (-1);
}
