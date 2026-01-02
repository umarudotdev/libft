/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_allocator.c                              :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator.h"
#include "ft_arena.h"

static void	*arena_alloc(void *context, size_t size);
static void	*arena_realloc(void *context, void *ptr, size_t old_size,
				size_t new_size);
static void	arena_free(void *context, void *ptr);

/**
 * @brief Returns an allocator that uses the given arena.
 *
 * @param arena The arena to allocate from.
 * @return The arena allocator.
 */
t_allocator	ft_arena_allocator(t_arena arena)
{
	static const t_allocator_vtable vtable = {
		.alloc = arena_alloc,
		.realloc = arena_realloc,
		.free = arena_free,
	};
	return ((t_allocator){
		.vtable = &vtable,
		.context = arena,
	});
}

static void	*arena_alloc(void *context, size_t size)
{
	return (ft_arena_alloc((t_arena)context, size));
}

static void	*arena_realloc(void *context, void *ptr, size_t old_size,
		size_t new_size)
{
	return (ft_arena_realloc((t_arena)context, ptr, old_size, new_size));
}

static void	arena_free(void *context, void *ptr)
{
	(void)context;
	(void)ptr;
}
