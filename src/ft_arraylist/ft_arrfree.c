/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfree.c                                      :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 01:47:38 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator.h"
#include "ft_arraylist.h"
#include "ft_arraylist_internal.h"

/**
 * @brief Frees the array pointed to by `arr`.
 *
 * @param arr A pointer to the array to be freed.
 */
void	ft_arrfree(t_array *arr)
{
	if (!arr)
		return ;
	ft_free(arr->allocator, arr->elements);
	ft_free(arr->allocator, arr);
}
