/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_none.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"
#include <stddef.h>

/**
 * @brief Creates an empty Option (None state).
 *
 * This function constructs an Option that contains no value. This represents
 * the absence of a value in a type-safe way, avoiding the need for `NULL`
 * pointer checks.
 *
 * @return An Option in the None state
 */
t_option	ft_option_none(void)
{
	return ((t_option){
		._is_some = false,
		._value = NULL,
	});
}
