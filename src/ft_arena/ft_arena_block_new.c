/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_block_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/26 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena_int.h"
#include <stdlib.h>

/**
 * @brief Creates a new arena block with the given capacity.
 *
 * Allocates a new block with extra space for alignment. The block's buffer
 * starts after the header and is aligned to `ARENA_ALIGNMENT` bytes.
 *
 * @param capacity The usable capacity of the block in bytes.
 * @return A pointer to the new block, or `NULL` if allocation failed.
 */
struct s_arena_block	*ft_arena_block_new(size_t capacity)
{
	struct s_arena_block	*block;

	block = malloc(sizeof(struct s_arena_block) + capacity + ARENA_ALIGNMENT);
	if (!block)
		return (NULL);
	block->next = NULL;
	block->size = 0;
	block->capacity = capacity;
	return (block);
}
