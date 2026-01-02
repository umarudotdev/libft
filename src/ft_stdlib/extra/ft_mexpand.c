/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mexpand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:58:08 by martins           #+#    #+#             */
/*   Updated: 2024/09/14 20:02:43 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator.h"
#include "ft_string.h"
#include <stddef.h>
#include <sys/param.h>

/**
 * @brief Changes the size of the memory block pointed to by `ptr`.
 *
 * If `ptr` is NULL, then the call is equivalent to ft_alloc(a, new_size).
 *
 * If `new_size` is equal to zero, and `ptr` is not NULL, then the call is
 * equivalent to ft_free(a, ptr) and returns NULL.
 *
 * @param a The allocator to use.
 * @param ptr A pointer to the memory block to expand.
 * @param old_size The old size of the memory block.
 * @param new_size The new size of the memory block.
 * @return A pointer to the allocated memory. NULL if an error occurred.
 */
void	*ft_mexpand(t_allocator a, void *ptr, size_t old_size, size_t new_size)
{
	void	*new;

	if (!ptr)
		return (ft_alloc(a, new_size));
	if (new_size == 0)
	{
		ft_free(a, ptr);
		return (NULL);
	}
	new = ft_alloc(a, new_size);
	if (!new)
		return (NULL);
	ft_memcpy(new, ptr, MIN(old_size, new_size));
	ft_free(a, ptr);
	return (new);
}
