/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocator.h                                    :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALLOCATOR_H
# define FT_ALLOCATOR_H

# include <stddef.h>

typedef struct s_allocator_vtable
{
	void						*(*alloc)(void *context, size_t size);
	void						*(*realloc)(void *context, void *ptr,
								size_t old_size, size_t new_size);
	void						(*free)(void *context, void *ptr);
}								t_allocator_vtable;

typedef struct s_allocator
{
	const t_allocator_vtable	*vtable;
	void						*context;
}								t_allocator;

void							*ft_alloc(t_allocator a, size_t size);
void							*ft_realloc(t_allocator a, void *ptr,
									size_t old_size, size_t new_size);
void							ft_free(t_allocator a, void *ptr);
t_allocator						ft_heap_allocator(void);

#endif
