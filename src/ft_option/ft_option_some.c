/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_some.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"

/**
 * @brief Creates an Option containing a value (Some state).
 *
 * This function constructs an Option that contains a value. The value can be
 * any pointer type. Note that passing `NULL` will create a Some(`NULL`), which
 * is different from None.
 *
 * @param value The value to wrap in an Option
 * @return An Option in the Some state containing the value
 */
t_option	ft_option_some(const void *value)
{
	return ((t_option){
		._is_some = true,
		._value = value,
	});
}
