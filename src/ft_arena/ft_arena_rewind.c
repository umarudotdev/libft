/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_rewind.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/26 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena_int.h"
#include <stdlib.h>

/**
 * @brief Rewinds the arena to a previous snapshot state.
 *
 * Restores the arena to the state captured by ft_arena_snapshot(),
 * effectively freeing all allocations made after the snapshot.
 * Blocks allocated after the snapshot are freed.
 *
 * @param arena The arena to rewind.
 * @param mark The snapshot to rewind to.
 */
void	ft_arena_rewind(t_arena arena, t_arena_mark mark)
{
	struct s_arena_block	*block;
	struct s_arena_block	*next;
	struct s_arena_block	*mark_block;

	if (!arena)
		return ;
	mark_block = mark.block;
	if (!mark_block)
	{
		ft_arena_reset(arena);
		return ;
	}
	block = mark_block->next;
	while (block)
	{
		next = block->next;
		free(block);
		block = next;
	}
	mark_block->next = NULL;
	mark_block->size = mark.size;
	arena->current = mark_block;
}
