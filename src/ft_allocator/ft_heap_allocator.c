/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heap_allocator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator.h"
#include <stdlib.h>

static void	*heap_alloc(void *context, size_t size);
static void	*heap_realloc(void *context, void *ptr, size_t old_size,
				size_t new_size);
static void	heap_free(void *context, void *ptr);

/**
 * @brief Returns the heap allocator (uses malloc/realloc/free).
 *
 * @return The heap allocator.
 */
t_allocator	ft_heap_allocator(void)
{
	static const t_allocator_vtable vtable = {
		.alloc = heap_alloc,
		.realloc = heap_realloc,
		.free = heap_free,
	};
	return ((t_allocator){
		.vtable = &vtable,
		.context = NULL,
	});
}

static void	*heap_alloc(void *context, size_t size)
{
	(void)context;
	return (malloc(size));
}

static void	*heap_realloc(void *context, void *ptr, size_t old_size,
		size_t new_size)
{
	(void)context;
	(void)old_size;
	return (realloc(ptr, new_size));
}

static void	heap_free(void *context, void *ptr)
{
	(void)context;
	free(ptr);
}
