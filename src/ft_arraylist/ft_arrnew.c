/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:31:59 by martins           #+#    #+#             */
/*   Updated: 2024/09/14 20:02:41 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator.h"
#include "ft_arraylist.h"
#include <stddef.h>

/**
 * @brief Allocates and returns a new array using the heap allocator.
 *
 * @param size The size in bytes of the elements to be stored in the array.
 * @return The new array.
 */
t_array	*ft_arrnew(size_t size)
{
	return (ft_arrnew_allocator(ft_heap_allocator(), size));
}
