/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_int.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/26 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARENA_INTERNAL_H
# define FT_ARENA_INTERNAL_H

# include "ft_arena.h"
# include <stddef.h>

# define ARENA_DEFAULT_CAPACITY 4096
# define ARENA_ALIGNMENT 16

struct						s_arena_block
{
	struct s_arena_block	*next;
	size_t					size;
	size_t					capacity;
	char					buffer[];
};

struct						s_arena
{
	struct s_arena_block	*head;
	struct s_arena_block	*current;
	size_t					block_capacity;
};

size_t						ft_arena_align(size_t size);
char						*ft_arena_align_ptr(char *ptr);
struct s_arena_block		*ft_arena_block_new(size_t capacity);
void						*ft_arena_alloc_from_block(struct s_arena_block *block,
								size_t size);
void						*ft_arena_alloc_new_block(t_arena arena,
								size_t size);

#endif
