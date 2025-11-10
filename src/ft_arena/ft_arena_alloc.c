/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_alloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena_int.h"
#include <stdint.h>
#include <stdlib.h>

static size_t				align_size(size_t size);
static struct s_arena_block	*create_new_block(t_arena *arena, size_t size);

/**
 * @brief Allocates memory from the arena.
 *
 * This function allocates memory from the arena with proper alignment.
 * If the current block doesn't have enough space, a new block is allocated.
 * Memory is not initialized.
 *
 * @param arena The arena to allocate from.
 * @param size The number of bytes to allocate.
 * @return A pointer to the allocated memory. NULL if allocation fails or
 *         if arena is NULL.
 */
void	*ft_arena_alloc(t_arena *arena, size_t size)
{
	struct s_arena_block	*block;
	void					*ptr;
	size_t					aligned_size;

	if (!arena || size == 0)
		return (NULL);
	aligned_size = align_size(size);
	block = arena->current;
	if (block->used + aligned_size > block->size)
	{
		block = create_new_block(arena, aligned_size);
		if (!block)
			return (NULL);
		arena->current = block;
	}
	ptr = (unsigned char *)block->data + block->used;
	block->used += aligned_size;
	return (ptr);
}

static size_t	align_size(size_t size)
{
	return ((size + ARENA_ALIGNMENT - 1) & ~(ARENA_ALIGNMENT - 1));
}

static struct s_arena_block	*create_new_block(t_arena *arena, size_t size)
{
	struct s_arena_block	*block;
	size_t					block_size;

	block_size = arena->block_size;
	if (size > block_size)
		block_size = size;
	block = malloc(sizeof(struct s_arena_block));
	if (!block)
		return (NULL);
	block->data = malloc(block_size);
	if (!block->data)
	{
		free(block);
		return (NULL);
	}
	block->size = block_size;
	block->used = 0;
	block->next = NULL;
	arena->current->next = block;
	return (block);
}
