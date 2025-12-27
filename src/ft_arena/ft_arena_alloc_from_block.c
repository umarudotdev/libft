/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_alloc_from_block.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/26 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena_int.h"

/**
 * @brief Allocates memory from a specific arena block.
 *
 * Bumps the block's allocation pointer and returns the previous position.
 * The caller must ensure the block has sufficient capacity.
 *
 * @param block The block to allocate from.
 * @param size The number of bytes to allocate (must be pre-aligned).
 * @return A pointer to the allocated memory.
 */
void	*ft_arena_alloc_from_block(struct s_arena_block *block, size_t size)
{
	char	*base;
	void	*ptr;

	base = ft_arena_align_ptr(block->buffer);
	ptr = base + block->size;
	block->size += size;
	return (ptr);
}
