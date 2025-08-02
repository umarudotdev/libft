/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_map_err.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_result.h"

/**
 * @brief Maps a Result by applying a function to the Err value.
 *
 * This function transforms the Err value of a Result by applying the given
 * function to it. If the Result is Ok, it returns the Ok unchanged. This is
 * useful for error recovery and transformation.
 *
 * @param result The Result to map the error of
 * @param f The function to apply to the Err value
 * @return A new Result with the transformed Err value, or the original Ok
 */
t_result	ft_result_map_err(t_result result, const void *(*f)(const void *))
{
	if (!f)
		return (result);
	if (!result._is_ok)
		return (ft_result_err(f(result._err_value)));
	return (result);
}
