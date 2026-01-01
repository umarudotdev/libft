/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_trim.c                                    :+:      :+:    :+:   */
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
 * @brief Frees unused blocks after the current block.
 *
 * Reduces memory footprint by freeing any blocks that were allocated
 * but are no longer in use (after the current allocation point).
 *
 * @param arena The arena to trim.
 */
void	ft_arena_trim(t_arena arena)
{
	struct s_arena_block	*block;
	struct s_arena_block	*next;

	if (!arena || !arena->current)
		return ;
	block = arena->current->next;
	while (block)
	{
		next = block->next;
		free(block);
		block = next;
	}
	arena->current->next = NULL;
}
