/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_with_location.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

/**
 * @brief Creates a new error with source location information.
 *
 * This is typically used via the FT_ERROR macro which automatically
 * fills in __FILE__ and __LINE__.
 *
 * @param kind The error category
 * @param message A descriptive error message
 * @param file The source file where the error occurred
 * @param line The line number where the error occurred
 * @return A new error structure with location info
 *
 * @example
 *   t_error err = FT_ERROR(FT_ERR_INVALID_INPUT, "Invalid parameter");
 */
t_error	ft_error_with_location(t_error_kind kind, const char *message,
		const char *file, int line)
{
	t_error	error;

	error.kind = kind;
	error.message = message;
	error.context = NULL;
	error.file = file;
	error.line = line;
	error.code = (int)kind;
	return (error);
}
