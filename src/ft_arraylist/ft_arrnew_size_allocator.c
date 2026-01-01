/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew_size_allocator.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arraylist.h"
#include "ft_arraylist_internal.h"
#include "ft_string.h"
#include <stddef.h>

/**
 * @brief Allocates and returns a new array using the given allocator.
 *
 * @param alloc The allocator to use.
 * @param size The size in bytes of the elements to be stored in the array.
 * @param capacity The initial capacity of the array.
 * @return The new array.
 */
t_array	*ft_arrnew_size_allocator(t_allocator a, size_t size, size_t capacity)
{
	t_array	*arr;

	arr = ft_alloc(a, sizeof(t_array));
	if (!arr)
		return (NULL);
	arr->elements = ft_alloc(a, (capacity + 1) * size);
	if (!arr->elements)
		return (ft_free(a, arr), NULL);
	ft_bzero(arr->elements, (capacity + 1) * size);
	arr->element_size = size;
	arr->size = 0;
	arr->capacity = capacity;
	arr->allocator = a;
	return (arr);
}
