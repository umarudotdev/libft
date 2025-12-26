/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_alloc_from_block.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/26 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena_int.h"

void	*ft_arena_alloc_from_block(struct s_arena_block *block, size_t size)
{
	char	*base;
	void	*ptr;

	base = ft_arena_align_ptr(block->buffer);
	ptr = base + block->size;
	block->size += size;
	return (ptr);
}
