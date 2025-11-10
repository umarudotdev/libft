/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_new_opt.c                                 :+:      :+:    :+:   */
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
 * @brief Creates a new arena allocator, returning an Option.
 *
 * This is a safe wrapper around ft_arena_new that returns an Option type
 * instead of a raw pointer. This allows for better error handling using
 * the monadic Option API.
 *
 * @param block_size The size of each memory block in bytes. If 0, uses
 *                   ARENA_DEFAULT_BLOCK_SIZE (4096 bytes).
 * @return A Some(arena) if successful, None if allocation fails.
 *
 * @example
 *   t_option opt = ft_arena_new_opt(4096);
 *   if (ft_option_is_some(opt)) {
 *       t_arena *arena = ft_option_unwrap(opt);
 *       // use arena
 *   }
 */
t_option	ft_arena_new_opt(size_t block_size)
{
	return (ft_option_from_ptr(ft_arena_new(block_size)));
}
