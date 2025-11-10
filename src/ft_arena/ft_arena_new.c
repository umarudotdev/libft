/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena_int.h"
#include <stdlib.h>

static struct s_arena_block	*create_block(size_t size);

/**
 * @brief Creates a new arena allocator with the specified block size.
 *
 * An arena allocator is a memory management technique that allocates memory
 * from large blocks and allows freeing all allocations at once. This is
 * useful for temporary allocations that have the same lifetime.
 *
 * @param block_size The size of each memory block in bytes. If 0, uses
 *                   ARENA_DEFAULT_BLOCK_SIZE (4096 bytes).
 * @return A pointer to the new arena. NULL if allocation fails.
 */
t_arena	*ft_arena_new(size_t block_size)
{
	t_arena	*arena;

	if (block_size == 0)
		block_size = ARENA_DEFAULT_BLOCK_SIZE;
	arena = malloc(sizeof(t_arena));
	if (!arena)
		return (NULL);
	arena->first = create_block(block_size);
	if (!arena->first)
	{
		free(arena);
		return (NULL);
	}
	arena->current = arena->first;
	arena->block_size = block_size;
	return (arena);
}

static struct s_arena_block	*create_block(size_t size)
{
	struct s_arena_block	*block;

	block = malloc(sizeof(struct s_arena_block));
	if (!block)
		return (NULL);
	block->data = malloc(size);
	if (!block->data)
	{
		free(block);
		return (NULL);
	}
	block->size = size;
	block->used = 0;
	block->next = NULL;
	return (block);
}
