/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_strdup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/26 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena_int.h"
#include "ft_string.h"

/**
 * @brief Duplicates a string into the arena.
 *
 * Allocates memory from the arena and copies the source string into it,
 * including the null terminator.
 *
 * @param arena The arena to allocate from.
 * @param str The source string to duplicate.
 * @return A pointer to the duplicated string, or `NULL` on failure.
 */
char	*ft_arena_strdup(t_arena arena, const char *str)
{
	size_t	len;
	char	*ptr;

	if (!str)
		return (NULL);
	len = ft_strlen(str) + 1;
	ptr = ft_arena_alloc(arena, len);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, str, len);
	return (ptr);
}
