/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_memdup.c                                  :+:      :+:    :+:   */
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
 * @brief Duplicates a memory region into the arena.
 *
 * Allocates memory from the arena and copies the source data into it.
 *
 * @param arena The arena to allocate from.
 * @param src The source memory to duplicate.
 * @param size The number of bytes to duplicate.
 * @return A pointer to the duplicated memory, or `NULL` on failure.
 */
void	*ft_arena_memdup(t_arena arena, const void *src, size_t size)
{
	void	*ptr;

	if (!src || size == 0)
		return (NULL);
	ptr = ft_arena_alloc(arena, size);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, src, size);
	return (ptr);
}
