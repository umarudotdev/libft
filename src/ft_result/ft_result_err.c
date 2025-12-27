/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_result.h"

/**
 * @brief Creates a Result in the Err state with the given error value.
 *
 * This function constructs a failed Result that contains an error value. The
 * error can be any pointer type, such as an error message string, error code,
 * or custom error structure.
 *
 * @param error The error value to wrap in a failed Result
 * @return A Result in the Err state containing the error value
 */
t_result	ft_result_err(const void *error)
{
	return ((t_result){
		._is_ok = false,
		._err_value = error,
	});
}
