/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include <unistd.h>

/**
 * @brief Prints error information to stderr.
 *
 * Formats and prints the error in a structured way with kind, message,
 * context, and location information if available.
 *
 * @param error Pointer to the error structure to print
 *
 * @example Output:
 *   Error [Parse error]: Integer overflow
 *   Context: parsing '999999999999999'
 *   Location: src/ft_stdlib/ft_atoi.c:45
 */
void	ft_error_print(const t_error *error)
{
	ft_error_print_fd(error, STDERR_FILENO);
}
