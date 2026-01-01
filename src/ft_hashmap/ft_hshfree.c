/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hshfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:29:49 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arraylist.h"
#include "ft_hashmap.h"
#include "ft_hashmap_internal.h"

/**
 * @brief Frees the hash map pointed to by `hsh`.
 *
 * @param hsh A pointer to the hash map to be freed.
 */
void	ft_hshfree(t_hashmap *hsh)
{
	if (!hsh)
		return ;
	ft_arrfree(hsh->entries);
	ft_free(hsh->allocator, hsh);
}
