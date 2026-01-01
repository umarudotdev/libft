/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stnnew_size_allocator.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_int.h"
#include <stddef.h>

/**
 * @brief Allocates and returns a new binary-safe string with the given size
 * using the provided allocator.
 *
 * @param a The allocator to use.
 * @param s The content to create the string with.
 * @param size The size of the string.
 * @return The new string.
 */
t_string	ft_stnnew_size_allocator(t_allocator a, const char *s, size_t size)
{
	t_string				stn;
	static const size_t		header_size = sizeof(struct s_string_header);
	struct s_string_header	*ptr;

	ptr = ft_alloc(a, header_size + size + 1);
	if (!ptr)
		return (NULL);
	ptr->allocator = a;
	ptr->size = size;
	ptr->capacity = size;
	stn = ptr->buffer;
	if (s)
		ft_memcpy(stn, s, size);
	else
		ft_bzero(stn, size);
	stn[size] = '\0';
	return (stn);
}
