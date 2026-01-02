/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_alloc_new_block.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/26 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena.h"
#include "ft_arena_internal.h"

/**
 * @brief Allocates memory from a newly created arena block.
 *
 * Creates a new block and links it to the arena's block list. If the requested
 * size exceeds the default block capacity, a larger block is allocated.
 *
 * @param arena The arena to allocate from.
 * @param size The number of bytes to allocate (must be pre-aligned).
 * @return A pointer to the allocated memory, or `NULL` if allocation failed.
 */
void	*ft_arena_alloc_new_block(t_arena arena, size_t size)
{
	struct s_arena_block	*block;
	size_t					capacity;

	capacity = arena->block_capacity;
	if (size > capacity)
		capacity = size;
	block = ft_arena_block_new(capacity);
	if (!block)
		return (NULL);
	if (arena->current)
		arena->current->next = block;
	else
		arena->head = block;
	arena->current = block;
	return (ft_arena_alloc_from_block(block, size));
}
