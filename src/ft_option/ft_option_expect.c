/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_expect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"
#include "ft_stdlib.h"

/**
 * @brief Unwraps an Option, yielding the content of a Some.
 *
 * This function returns the contained Some value. If the Option is None, it
 * panics with the provided message. Use this when you have a custom error
 * message to display on failure.
 *
 * @param option The Option to unwrap
 * @param message The error message to display if None
 * @return The contained Some value
 * @note This function will panic if the Option is None
 */
void	*ft_option_expect(t_option option, const char *message)
{
	if (!option._is_some)
	{
		if (message)
			ft_panic(message);
		else
			ft_panic("called `ft_option_expect` on a None value");
	}
	return ((void *)option._value);
}
