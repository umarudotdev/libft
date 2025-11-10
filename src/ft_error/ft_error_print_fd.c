/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_print_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_stdio.h"

static void	print_number(int n, int fd);

/**
 * @brief Prints error information to specified file descriptor.
 *
 * @param error Pointer to the error structure to print
 * @param fd File descriptor to write to
 */
void	ft_error_print_fd(const t_error *error, int fd)
{
	if (!error)
		return ;
	ft_putstr_fd("Error [", fd);
	ft_putstr_fd((char *)ft_error_kind_str(error->kind), fd);
	ft_putstr_fd("]: ", fd);
	ft_putendl_fd((char *)ft_error_message(error), fd);
	if (error->context && error->context[0])
	{
		ft_putstr_fd("  Context: ", fd);
		ft_putendl_fd((char *)error->context, fd);
	}
	if (error->file)
	{
		ft_putstr_fd("  Location: ", fd);
		ft_putstr_fd((char *)error->file, fd);
		ft_putchar_fd(':', fd);
		print_number(error->line, fd);
		ft_putchar_fd('\n', fd);
	}
}

static void	print_number(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		print_number(n / 10, fd);
	c = '0' + (n % 10);
	ft_putchar_fd(c, fd);
}
