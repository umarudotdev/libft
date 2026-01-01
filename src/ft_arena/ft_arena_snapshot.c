/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_snapshot.c                                :+:      :+:    :+:   */
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
 * @brief Captures the current allocation state of the arena.
 *
 * Returns a snapshot that can later be passed to `ft_arena_rewind()` to
 * restore the arena to this state, effectively freeing all allocations
 * made after the snapshot.
 *
 * @param arena The arena to snapshot.
 * @return A mark representing the current allocation state.
 */
t_arena_mark	ft_arena_snapshot(t_arena arena)
{
	t_arena_mark	mark;

	if (!arena || !arena->current)
	{
		mark.block = NULL;
		mark.size = 0;
		return (mark);
	}
	mark.block = arena->current;
	mark.size = arena->current->size;
	return (mark);
}
