/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator.h"

/**
 * @brief Resizes memory using the given allocator.
 *
 * @param a The allocator to use.
 * @param ptr The pointer to resize.
 * @param old_size The old size of the memory.
 * @param new_size The new size of the memory.
 * @return A pointer to the resized memory, or `NULL` on failure.
 */
void	*ft_realloc(t_allocator a, void *ptr, size_t old_size, size_t new_size)
{
	return (a.vtable->realloc(a.context, ptr, old_size, new_size));
}
