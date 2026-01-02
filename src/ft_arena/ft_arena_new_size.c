/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_new_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/26 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena.h"
#include "ft_arena_internal.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * @brief Creates a new arena allocator.
 *
 * An arena allocator is a memory allocation strategy that allocates memory
 * from a pre-allocated block. Individual allocations cannot be freed; instead,
 * the entire arena is freed or reset at once. This is efficient for scenarios
 * where many small allocations are made and freed together.
 *
 * The arena uses lazy allocation: no memory blocks are allocated until the
 * first allocation request is made.
 *
 * @param capacity The initial capacity of the arena in bytes.
 * @return A pointer to the new arena, or `NULL` if allocation failed.
 */
t_arena	ft_arena_new_size(size_t capacity)
{
	struct s_arena	*arena;

	arena = malloc(sizeof(struct s_arena));
	if (!arena)
		return (NULL);
	arena->head = NULL;
	arena->current = NULL;
	arena->block_capacity = capacity;
	return (arena);
}
