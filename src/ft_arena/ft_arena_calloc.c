/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_calloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena.h"
#include "ft_string.h"

/**
 * @brief Allocates zeroed memory from the arena.
 *
 * This function allocates memory from the arena and initializes all bytes
 * to zero.
 *
 * @param arena The arena to allocate from.
 * @param size The number of bytes to allocate.
 * @return A pointer to the allocated and zeroed memory. NULL if allocation
 *         fails or if arena is NULL.
 */
void	*ft_arena_calloc(t_arena *arena, size_t size)
{
	void	*ptr;

	ptr = ft_arena_alloc(arena, size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}
