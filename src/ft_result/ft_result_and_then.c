/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_and_then.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_result.h"
#include "ft_stdlib.h"

/**
 * @brief Chains Result-returning operations (monadic bind).
 *
 * This function implements the monadic bind operation for Results. It applies
 * the given function to the Ok value if the Result is Ok, and returns the Err
 * unchanged if the Result is Err. This allows for composing operations that
 * may fail.
 *
 * @param result The Result to bind
 * @param f A function that takes the Ok value and returns a new Result
 * @return The Result returned by `f`, or the original Err
 */
t_result	ft_result_and_then(t_result result, t_result (*f)(const void *))
{
	if (!f)
		return (ft_result_err(NULL));
	if (result._is_ok)
		return (f(result._ok_value));
	return (result);
}
