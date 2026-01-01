/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hshnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:29:55 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashmap.h"

/**
 * @brief Allocates and returns a new hash map using the heap allocator.
 * If `hash` is NULL, the default hash function will be used.
 *
 * @param hash The hash function to use.
 * @return The new hash map.
 */
t_hashmap	*ft_hshnew(t_hash_func hash)
{
	return (ft_hshnew_allocator(ft_heap_allocator(), hash));
}
