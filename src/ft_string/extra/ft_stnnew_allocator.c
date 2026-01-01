/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stnnew_allocator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/**
 * @brief Allocates and returns a new binary-safe string using the provided
 * allocator.
 *
 * @param a The allocator to use.
 * @param s The content to create the string with.
 * @return The new string.
 */
t_string	ft_stnnew_allocator(t_allocator a, const char *s)
{
	if (!s)
		return (ft_stnnew_empty_allocator(a));
	return (ft_stnnew_size_allocator(a, s, ft_strlen(s)));
}
