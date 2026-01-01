/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_reset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/26 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena.h"
#include "ft_arena_internal.h"
#include <stdlib.h>

/**
 * @brief Resets the arena for reuse.
 *
 * Resets all allocation pointers to the beginning, allowing the arena to be
 * reused without freeing and reallocating memory. All extra blocks except
 * the first one are freed to avoid memory leaks.
 *
 * @param arena The arena to reset.
 */
void	ft_arena_reset(t_arena arena)
{
	struct s_arena_block	*block;
	struct s_arena_block	*next;

	if (!arena || !arena->head)
		return ;
	block = arena->head->next;
	while (block)
	{
		next = block->next;
		free(block);
		block = next;
	}
	arena->head->next = NULL;
	arena->head->size = 0;
	arena->current = arena->head;
}
