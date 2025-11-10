/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_int.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARENA_INT_H
# define FT_ARENA_INT_H

# include "ft_arena.h"
# include <stddef.h>

# define ARENA_DEFAULT_BLOCK_SIZE 4096
# define ARENA_ALIGNMENT 16

struct			s_arena_block
{
	void		*data;
	size_t		size;
	size_t		used;
	struct s_arena_block	*next;
};

struct			s_arena
{
	struct s_arena_block	*first;
	struct s_arena_block	*current;
	size_t					block_size;
};

#endif
