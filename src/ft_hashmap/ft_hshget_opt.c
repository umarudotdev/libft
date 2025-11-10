/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hshget_opt.c                                    :+:      :+:    :+:   */
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
 * @brief Gets a value from the hash map, returning an Option.
 *
 * This is a safe wrapper around ft_hshget that returns an Option type
 * for better handling of missing keys.
 *
 * @param hsh A pointer to the hash map to get the value from.
 * @param key The key to get the value for.
 * @return A Some(value) if key exists, None if key not found.
 *
 * @example
 *   t_option opt = ft_hshget_opt(map, "name");
 *   char *name = ft_option_unwrap_or(opt, "unknown");
 */
t_option	ft_hshget_opt(const t_hashmap *hsh, const char *key)
{
	return (ft_option_from_ptr(ft_hshget(hsh, key)));
}
