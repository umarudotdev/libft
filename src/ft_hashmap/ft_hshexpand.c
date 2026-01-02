/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hshexpand.c                                    :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:24:10 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arraylist_internal.h"
#include "ft_hashmap.h"
#include "ft_hashmap_internal.h"
#include <stddef.h>

static void	set_entry(t_array *entries, struct s_entry *entry, size_t index);

/**
 * @brief Expands the hash map to the new size, rehashing all the entries.
 *
 * @param hsh A pointer to the hash map to expand.
 * @param size The new size of the hash map.
 * @return The expanded hash map. `NULL` if the allocation fails.
 */
t_hashmap	*ft_hshexpand(t_hashmap *hsh, size_t size)
{
	t_array			*tmp;
	size_t			i;
	struct s_entry	*entry;
	size_t			index;

	tmp = ft_arrnew_size_allocator(hsh->allocator, sizeof(struct s_entry),
			size);
	if (!tmp)
		return (ft_arrfree(tmp), NULL);
	hsh->size = 0;
	i = 0;
	while (i < ft_arrcap(hsh->entries))
	{
		entry = ft_arrat(hsh->entries, i);
		if (entry->key != NULL)
		{
			index = hsh->hash(entry->key) % ft_arrcap(tmp);
			set_entry(tmp, entry, index);
			hsh->size++;
		}
		i++;
	}
	ft_arrfree(hsh->entries);
	hsh->entries = tmp;
	return (hsh);
}

static void	set_entry(t_array *entries, struct s_entry *entry, size_t index)
{
	struct s_entry	*pairs;

	pairs = entries->elements;
	if (pairs[index].key == NULL)
	{
		ft_arrinsert(entries, entry, index);
		return ;
	}
	set_entry(entries, entry, (index + 1) % ft_arrcap(entries));
}
