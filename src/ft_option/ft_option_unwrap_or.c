/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_unwrap_or.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"

/**
 * @brief Returns the contained Some value or a provided default.
 *
 * This function safely extracts the value from an Option. If the Option is
 * Some, it returns the contained value. If the Option is None, it returns the
 * provided default value instead. This is a safe alternative to unwrap.
 *
 * @param option The Option to extract from
 * @param default_value The value to return if Option is None
 * @return The contained Some value or the default value if None
 */
void	*ft_option_unwrap_or(t_option option, const void *default_value)
{
	if (option._is_some)
		return ((void *)option._value);
	return ((void *)default_value);
}
