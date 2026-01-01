/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stncap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 06:12:27 by martins           #+#    #+#             */
/*   Updated: 2024/09/14 20:04:17 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_internal.h"
#include <stddef.h>

/**
 * @brief Returns the capacity of the binary-safe string `s`.
 *
 * @param s The string to be checked.
 * @return The capacity of the string.
 */
size_t	ft_stncap(const t_string s)
{
	return (ft_stnhdr(s)->capacity);
}
