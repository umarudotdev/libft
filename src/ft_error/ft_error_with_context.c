/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_with_context.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

/**
 * @brief Creates a new error with additional context information.
 *
 * @param kind The error category
 * @param message A descriptive error message
 * @param context Additional context about where/why the error occurred
 * @return A new error structure with context
 *
 * @example
 *   t_error err = ft_error_with_context(FT_ERR_NULL_POINTER,
 *       "Null pointer dereference", "in ft_strdup argument");
 */
t_error	ft_error_with_context(t_error_kind kind, const char *message,
		const char *context)
{
	t_error	error;

	error.kind = kind;
	error.message = message;
	error.context = context;
	error.file = NULL;
	error.line = 0;
	error.code = (int)kind;
	return (error);
}
