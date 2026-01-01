/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stnnew_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 02:47:46 by martins           #+#    #+#             */
/*   Updated: 2024/09/14 20:02:41 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>

/**
 * @brief Allocates (with malloc(3)) and returns a new binary-safe string with
 * the given size.
 *
 * @param s The content to create the string with.
 * @param size The size of the string.
 * @return The new string.
 */
t_string	ft_stnnew_size(const char *s, size_t size)
{
	return (ft_stnnew_size_allocator(ft_heap_allocator(), s, size));
}
