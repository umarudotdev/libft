/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/26 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARENA_H
# define FT_ARENA_H

# include <stddef.h>

typedef struct s_arena	*t_arena;

typedef struct s_arena_mark
{
	void				*block;
	size_t				size;
}						t_arena_mark;

t_arena					ft_arena_new(size_t capacity);
void					ft_arena_free(t_arena arena);
void					*ft_arena_alloc(t_arena arena, size_t size);
void					*ft_arena_calloc(t_arena arena, size_t nmemb,
							size_t size);
void					*ft_arena_realloc(t_arena arena, void *ptr,
							size_t old_size, size_t new_size);
void					*ft_arena_memdup(t_arena arena, const void *src,
							size_t size);
char					*ft_arena_strdup(t_arena arena, const char *str);
t_arena_mark			ft_arena_snapshot(t_arena arena);
void					ft_arena_rewind(t_arena arena, t_arena_mark mark);
void					ft_arena_trim(t_arena arena);
void					ft_arena_reset(t_arena arena);

#endif
