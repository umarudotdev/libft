/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_align.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/26 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena_internal.h"

/**
 * @brief Aligns a size to the arena alignment boundary.
 *
 * Rounds up the given size to the next multiple of `ARENA_ALIGNMENT`.
 *
 * @param size The size to align.
 * @return The aligned size.
 */
size_t	ft_arena_align(size_t size)
{
	return ((size + (ARENA_ALIGNMENT - 1)) & ~(ARENA_ALIGNMENT - 1));
}
