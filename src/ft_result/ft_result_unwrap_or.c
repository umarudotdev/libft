/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_unwrap_or.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_result.h"

/**
 * @brief Extracts the value from a Result or returns a default value.
 *
 * This function returns the contained Ok value if the Result is Ok, or the
 * provided default value if the Result is Err. This is a safe way to extract
 * values without risking a panic.
 *
 * @param result The Result to unwrap
 * @param default_value The value to return if the Result is Err
 * @return The Ok value if Result is Ok, otherwise the default value
 */
void	*ft_result_unwrap_or(t_result result, const void *default_value)
{
	if (result._is_ok)
		return ((void *)result._ok_value);
	return ((void *)default_value);
}
