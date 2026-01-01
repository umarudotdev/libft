/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_realloc.c                                 :+:      :+:    :+:   */
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
 * @brief Reallocates memory from the arena.
 *
 * Allocates new memory from the arena and copies the old data into it.
 * The old memory is not freed (arena allocators don't support individual
 * frees). If `new_size` is smaller than `old_size`, only `new_size` bytes are
 * copied.
 *
 * @param arena The arena to allocate from.
 * @param ptr The pointer to the old memory (can be `NULL`).
 * @param old_size The size of the old allocation.
 * @param new_size The size of the new allocation.
 * @return A pointer to the new memory, or `NULL` on failure.
 */
void	*ft_arena_realloc(t_arena arena, void *ptr, size_t old_size,
		size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

	if (new_size == 0)
		return (NULL);
	new_ptr = ft_arena_alloc(arena, new_size);
	if (!new_ptr)
		return (NULL);
	if (ptr && old_size > 0)
	{
		copy_size = old_size;
		if (new_size < old_size)
			copy_size = new_size;
		ft_memcpy(new_ptr, ptr, copy_size);
	}
	return (new_ptr);
}
