/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:31:59 by martins           #+#    #+#             */
/*   Updated: 2024/11/16 01:46:10 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arraylist.h"
#include <stddef.h>

/**
 * @brief Allocates and returns a new array using the heap allocator.
 *
 * @param size The size in bytes of the elements to be stored in the array.
 * @param capacity The initial capacity of the array.
 * @return The new array.
 */
t_array	*ft_arrnew_size(size_t size, size_t capacity)
{
	return (ft_arrnew_size_allocator(ft_heap_allocator(), size, capacity));
}
