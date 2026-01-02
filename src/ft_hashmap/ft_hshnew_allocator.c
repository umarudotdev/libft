/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hshnew_allocator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arraylist.h"
#include "ft_hashmap.h"
#include "ft_hashmap_internal.h"
#include <stddef.h>

/**
 * @brief Allocates and returns a new hash map using the given allocator.
 * If `hash` is `NULL`, the default hash function will be used.
 *
 * @param alloc The allocator to use.
 * @param hash The hash function to use.
 * @return The new hash map.
 */
t_hashmap	*ft_hshnew_allocator(t_allocator a, t_hash_func hash)
{
	t_hashmap	*hsh;

	hsh = ft_alloc(a, sizeof(t_hashmap));
	if (!hsh)
		return (NULL);
	hsh->entries = ft_arrnew_allocator(a, sizeof(struct s_entry));
	if (!hsh->entries)
		return (ft_free(a, hsh), NULL);
	hsh->size = 0;
	hsh->allocator = a;
	if (hash)
		hsh->hash = hash;
	else
		hsh->hash = ft_hshhash;
	return (hsh);
}
