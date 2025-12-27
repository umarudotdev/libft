/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_alloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/26 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena_int.h"

/**
 * @brief Allocates memory from the arena.
 *
 * Allocates `size` bytes from the arena. The memory is aligned to 16 bytes.
 * If the current block doesn't have enough space, a new block is allocated.
 * The returned memory is not initialized.
 *
 * @param arena The arena to allocate from.
 * @param size The number of bytes to allocate.
 * @return A pointer to the allocated memory, or NULL if allocation failed.
 */
void	*ft_arena_alloc(t_arena arena, size_t size)
{
	size_t	aligned_size;

	if (!arena || size == 0)
		return (NULL);
	aligned_size = ft_arena_align(size);
	if (!arena->current)
		return (ft_arena_alloc_new_block(arena, aligned_size));
	if (arena->current->size + aligned_size <= arena->current->capacity)
		return (ft_arena_alloc_from_block(arena->current, aligned_size));
	return (ft_arena_alloc_new_block(arena, aligned_size));
}
