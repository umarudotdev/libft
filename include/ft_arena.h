/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARENA_H
# define FT_ARENA_H

# include <stddef.h>

typedef struct s_arena	t_arena;

t_arena					*ft_arena_new(size_t block_size);
void					*ft_arena_alloc(t_arena *arena, size_t size);
void					*ft_arena_calloc(t_arena *arena, size_t size);
void					ft_arena_reset(t_arena *arena);
void					ft_arena_free(t_arena *arena);

#endif
