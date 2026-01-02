/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hshnew_hash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:29:55 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator.h"
#include "ft_hashmap.h"

/**
 * @brief Allocates and returns a new hash map using the heap allocator.
 *
 * @param hash The hash function to use, or NULL for the default.
 * @return The new hash map.
 */
t_hashmap	*ft_hshnew_hash(t_hash_func hash)
{
	return (ft_hshnew_hash_allocator(ft_heap_allocator(), hash));
}
