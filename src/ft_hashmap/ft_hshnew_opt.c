/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hshnew_opt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashmap.h"
#include "ft_option.h"

/**
 * @brief Creates a new hash map, returning an Option.
 *
 * This is a safe wrapper around ft_hshnew that returns an Option type
 * for better error handling.
 *
 * @param hash The hash function to use. If NULL, uses default hash function.
 * @return A Some(hashmap) if successful, None if allocation fails.
 *
 * @example
 *   t_option opt = ft_hshnew_opt(NULL);
 *   t_hashmap *map = ft_option_expect(opt, "failed to create hashmap");
 */
t_option	ft_hshnew_opt(t_hash_func hash)
{
	return (ft_option_from_ptr(ft_hshnew(hash)));
}
