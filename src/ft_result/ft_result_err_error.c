/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_err_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_result.h"
#include <stdlib.h>

/**
 * @brief Creates an Err Result containing a t_error structure.
 *
 * This function allocates memory for the error and returns a Result
 * containing it. The error should be freed by the caller when done.
 *
 * @param error The error structure to wrap in a Result
 * @return An Err Result containing the error
 *
 * @example
 *   t_error err = FT_ERROR(FT_ERR_INVALID_INPUT, "Invalid parameter");
 *   t_result res = ft_result_err_error(err);
 */
t_result	ft_result_err_error(t_error error)
{
	t_error		*error_ptr;
	t_result	result;

	error_ptr = malloc(sizeof(t_error));
	if (!error_ptr)
	{
		result._is_ok = false;
		result._with.err_value = NULL;
		return (result);
	}
	*error_ptr = error;
	return (ft_result_err(error_ptr));
}
