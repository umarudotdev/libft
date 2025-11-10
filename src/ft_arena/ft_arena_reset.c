/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_reset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena_int.h"

/**
 * @brief Resets the arena without freeing memory.
 *
 * This function resets all block usage counters to zero, effectively
 * reclaiming all allocated memory within the arena. The memory blocks
 * themselves are not freed, making subsequent allocations very fast.
 * This is useful when you need to reuse the arena for a new phase of
 * computation.
 *
 * @param arena The arena to reset. Does nothing if arena is NULL.
 */
void	ft_arena_reset(t_arena *arena)
{
	struct s_arena_block	*block;

	if (!arena)
		return ;
	block = arena->first;
	while (block)
	{
		block->used = 0;
		block = block->next;
	}
	arena->current = arena->first;
}
