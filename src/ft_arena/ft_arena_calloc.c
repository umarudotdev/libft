/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_calloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/26 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena.h"
#include "ft_arena_int.h"
#include "ft_string.h"

/**
 * @brief Allocates zeroed memory from the arena.
 *
 * Allocates memory for an array of `nmemb` elements of `size` bytes each
 * from the arena and initializes all bytes to zero.
 *
 * @param arena The arena to allocate from.
 * @param nmemb The number of elements to allocate.
 * @param size The size of each element.
 * @return A pointer to the allocated memory, or `NULL` if allocation failed
 * or if the multiplication would overflow.
 */
void	*ft_arena_calloc(t_arena arena, size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	bytes;

	if (size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	bytes = nmemb * size;
	ptr = ft_arena_alloc(arena, bytes);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, bytes);
	return (ptr);
}
