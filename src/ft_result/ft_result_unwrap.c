/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_unwrap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_result.h"
#include "ft_stdlib.h"

/**
 * @brief Extracts the value from an Ok Result, panics if Err.
 *
 * This function returns the contained Ok value. If the Result is Err, it calls
 * `ft_panic` to terminate the program. This should only be used when you are
 * certain the Result is Ok, or when a panic is acceptable.
 *
 * @param result The Result to unwrap
 * @return The contained Ok value
 * @note This function will panic if the Result is Err
 */
void	*ft_result_unwrap(t_result result)
{
	if (!result._is_ok)
		ft_panic("called `ft_result_unwrap` on an Err value");
	return ((void *)result._ok_value);
}
