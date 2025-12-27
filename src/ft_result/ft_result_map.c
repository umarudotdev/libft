/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_result.h"

/**
 * @brief Maps a Result by applying a function to the Ok value.
 *
 * This function transforms the Ok value of a Result by applying the given
 * function to it. If the Result is Err, it returns the Err unchanged. This
 * enables functional programming patterns and method chaining.
 *
 * @param result The Result to map
 * @param f The function to apply to the Ok value
 * @return A new Result with the transformed Ok value, or the original Err
 */
t_result	ft_result_map(t_result result, const void *(*f)(const void *))
{
	if (!f)
		return (result);
	if (result._is_ok)
		return (ft_result_ok(f(result._ok_value)));
	return (result);
}
