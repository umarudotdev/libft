/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_result.h"

/**
 * @brief Retrieves the t_error from an Err Result.
 *
 * This function assumes the Result contains a t_error pointer.
 * If called on an Ok Result or if the error is NULL, returns
 * a default "Unknown error".
 *
 * @param result The Result to extract the error from
 * @return Pointer to the t_error structure, or NULL if Result is Ok
 */
t_error	*ft_result_error(t_result result)
{
	if (result._is_ok)
		return (NULL);
	return ((t_error *)result._with.err_value);
}
