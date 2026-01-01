/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew_allocator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arraylist.h"
#include "ft_arraylist_int.h"
#include "ft_string.h"
#include <stddef.h>

/**
 * @brief Allocates and returns a new array using the given allocator.
 *
 * @param alloc The allocator to use.
 * @param size The size in bytes of the elements to be stored in the array.
 * @return The new array.
 */
t_array	*ft_arrnew_allocator(t_allocator a, size_t size)
{
	return (ft_arrnew_size_allocator(a, size, ARRAY_DEFAULT_CAPACITY));
}
