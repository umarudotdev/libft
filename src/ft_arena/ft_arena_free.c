/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_free.c                                    :+:      :+:    :+:   */
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
 * @brief Frees all memory associated with the arena.
 *
 * Frees all blocks allocated by the arena and the arena structure itself.
 * After calling this function, the arena pointer is invalid and should not
 * be used.
 *
 * @param arena The arena to free.
 */
void	ft_arena_free(t_arena arena)
{
	struct s_arena_block	*block;
	struct s_arena_block	*next;

	if (!arena)
		return ;
	block = arena->head;
	while (block)
	{
		next = block->next;
		free(block);
		block = next;
	}
	free(arena);
}
