/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stnsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 00:21:01 by martins           #+#    #+#             */
/*   Updated: 2024/09/14 20:02:41 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator.h"
#include "ft_arraylist.h"
#include "ft_string.h"

/**
 * @brief Splits a string by a character and returns an array of strings.
 *
 * @param s The string to split.
 * @param c The character to split by.
 * @return The array of strings. `NULL` if the allocation fails.
 */
t_array	*ft_stnsplit(const char *s, char c)
{
	return (ft_stnsplit_allocator(ft_heap_allocator(), s, c));
}
