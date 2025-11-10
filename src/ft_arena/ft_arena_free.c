/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena_int.h"
#include <stdlib.h>

/**
 * @brief Frees the arena and all its memory blocks.
 *
 * This function frees all memory allocated by the arena, including all
 * memory blocks and the arena structure itself. After calling this function,
 * the arena pointer should not be used.
 *
 * @param arena The arena to free. Does nothing if arena is NULL.
 */
void	ft_arena_free(t_arena *arena)
{
	struct s_arena_block	*block;
	struct s_arena_block	*next;

	if (!arena)
		return ;
	block = arena->first;
	while (block)
	{
		next = block->next;
		free(block->data);
		free(block);
		block = next;
	}
	free(arena);
}
