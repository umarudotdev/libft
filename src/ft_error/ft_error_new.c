/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

/**
 * @brief Creates a new error with kind and message.
 *
 * @param kind The error category
 * @param message A descriptive error message
 * @return A new error structure
 */
t_error	ft_error_new(t_error_kind kind, const char *message)
{
	t_error	error;

	error.kind = kind;
	error.message = message;
	error.context = NULL;
	error.file = NULL;
	error.line = 0;
	error.code = (int)kind;
	return (error);
}
