/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_unwrap.c                                 :+:      :+:    :+:   */
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
 * @brief Extracts the value from a Some Option, panics if None.
 *
 * This function returns the contained Some value. If the Option is None, it
 * calls `ft_panic` to terminate the program. This should only be used when you
 * are certain the Option is Some, or when a panic is acceptable.
 *
 * @param option The Option to unwrap
 * @return The contained Some value
 * @note This function will panic if the Option is None
 */
void	*ft_option_unwrap(t_option option)
{
	if (!option._is_some)
		ft_panic("called `ft_option_unwrap` on a None value");
	return ((void *)option._value);
}
