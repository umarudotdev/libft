/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stnsplit_space_allocator.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arraylist.h"
#include "ft_ctype.h"
#include "ft_string.h"
#include <stddef.h>

/**
 * @brief Splits a string by white-spaces and returns an array of strings
 * using the provided allocator.
 *
 * @param a The allocator to use.
 * @param s The string to split.
 * @return The array of strings. NULL if the allocation fails.
 */
t_array	*ft_stnsplit_space_allocator(t_allocator a, const char *s)
{
	t_array		*arr;
	size_t		i;
	size_t		j;
	t_string	str;

	arr = ft_arrnew_allocator(a, sizeof(t_string));
	if (!arr)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && ft_isspace(s[i]))
			i++;
		j = i;
		while (s[j] != '\0' && !ft_isspace(s[j]))
			j++;
		str = ft_stnnew_size_allocator(a, s + i, j - i);
		if (!str)
			return (ft_stnfreesplit(arr), NULL);
		if (!ft_arrappend(arr, &str))
			return (ft_stnfree(str), ft_stnfreesplit(arr), NULL);
		i = j;
	}
	return (arr);
}
