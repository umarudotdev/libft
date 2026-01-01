/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator.h"

/**
 * @brief Allocates memory using the given allocator.
 *
 * @param a The allocator to use.
 * @param size The size of the memory to allocate.
 * @return A pointer to the allocated memory, or `NULL` on failure.
 */
void	*ft_alloc(t_allocator a, size_t size)
{
	return (a.vtable->alloc(a.context, size));
}
