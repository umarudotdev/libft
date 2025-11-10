/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_calloc_opt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena.h"
#include "ft_option.h"

/**
 * @brief Allocates zeroed memory from the arena, returning an Option.
 *
 * This is a safe wrapper around ft_arena_calloc that returns an Option type
 * for better error handling.
 *
 * @param arena The arena to allocate from.
 * @param size The number of bytes to allocate.
 * @return A Some(ptr) if successful, None if allocation fails.
 */
t_option	ft_arena_calloc_opt(t_arena *arena, size_t size)
{
	return (ft_option_from_ptr(ft_arena_calloc(arena, size)));
}
