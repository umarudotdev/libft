/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stnnew_empty_allocator.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/**
 * @brief Allocates and returns a new, empty, binary-safe string using the
 * provided allocator.
 *
 * @param a The allocator to use.
 * @return The new string.
 */
t_string	ft_stnnew_empty_allocator(t_allocator a)
{
	return (ft_stnnew_size_allocator(a, "", 0));
}
