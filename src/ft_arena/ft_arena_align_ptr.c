/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_align_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/26 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena_int.h"
#include <stdint.h>

/**
 * @brief Aligns a pointer to the arena alignment boundary.
 *
 * Rounds up the given pointer to the next `ARENA_ALIGNMENT` boundary.
 *
 * @param ptr The pointer to align.
 * @return The aligned pointer.
 */
char	*ft_arena_align_ptr(char *ptr)
{
	uintptr_t	addr;

	addr = (uintptr_t)ptr;
	addr = (addr + (ARENA_ALIGNMENT - 1)) & ~(ARENA_ALIGNMENT - 1);
	return ((char *)addr);
}
