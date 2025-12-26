/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_block_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/26 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena_int.h"
#include <stdlib.h>

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
