/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_expect.c                                 :+:      :+:    :+:   */
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
 * @brief Extracts the Ok value or panics with a custom message.
 *
 * This function returns the contained Ok value if the Result is Ok, or calls
 * `ft_panic` with the provided message if the Result is Err. This provides
 * better error messages than `ft_result_unwrap`.
 *
 * @param result The Result to extract the value from
 * @param message The message to use if the Result is Err
 * @return The contained Ok value
 * @note This function will panic if the Result is Err
 */
void	*ft_result_expect(t_result result, const char *message)
{
	if (!result._is_ok)
	{
		if (message)
			ft_panic(message);
		else
			ft_panic("called `ft_result_expect` with Err and no message");
	}
	return ((void *)result._ok_value);
}
