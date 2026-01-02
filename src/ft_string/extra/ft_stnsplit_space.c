/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stnsplit_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 02:55:27 by martins           #+#    #+#             */
/*   Updated: 2024/09/14 20:05:17 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator.h"
#include "ft_arraylist.h"
#include "ft_string.h"

/**
 * @brief Splits a string by white-spaces and returns an array of strings.
 *
 * @param s The string to split.
 * @return The array of strings. `NULL` if the allocation fails.
 */
t_array	*ft_stnsplit_space(const char *s)
{
	return (ft_stnsplit_space_allocator(ft_heap_allocator(), s));
}
