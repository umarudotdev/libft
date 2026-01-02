/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2026/01/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * @brief Converts megabytes to bytes.
 *
 * @param n The number of megabytes.
 * @return The equivalent number of bytes.
 */
size_t	ft_mb(size_t n)
{
	return (n << 20);
}
