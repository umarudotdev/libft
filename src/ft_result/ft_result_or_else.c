/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_or_else.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_result.h"

/**
 * @brief Provides error recovery by applying a function to Err values.
 *
 * This function applies the given function to the Err value if the Result is
 * Err, allowing for error recovery. If the Result is Ok, it returns the Ok
 * unchanged. This is useful for fallback operations.
 *
 * @param result The Result to apply error recovery to
 * @param f A function that takes the Err value and returns a new Result
 * @return The Result returned by `f` if Err, or the original Ok
 */
t_result	ft_result_or_else(t_result result, t_result (*f)(const void *))
{
	if (!f)
		return (result);
	if (!result._is_ok)
		return (f(result._err_value));
	return (result);
}
