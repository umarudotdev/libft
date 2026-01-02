/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrexpand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 06:19:25 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arraylist.h"
#include "ft_arraylist_internal.h"
#include "ft_string.h"
#include <stddef.h>

/**
 * @brief Expands the capacity of the array to `size`.
 *
 * @param arr A pointer to the array to expand.
 * @param size The new capacity of the array.
 * @return The expanded array. `NULL` if the allocation fails.
 */
t_array	*ft_arrexpand(t_array *arr, size_t size)
{
	void	*tmp;
	size_t	new_bytes;
	size_t	old_bytes;

	if (size <= arr->capacity)
		return (arr);
	new_bytes = (size + 1) * arr->element_size;
	old_bytes = (arr->capacity + 1) * arr->element_size;
	tmp = ft_realloc(arr->allocator, arr->elements, old_bytes, new_bytes);
	if (!tmp)
		return (NULL);
	ft_bzero((char *)tmp + old_bytes, new_bytes - old_bytes);
	arr->elements = tmp;
	arr->capacity = size;
	return (arr);
}
