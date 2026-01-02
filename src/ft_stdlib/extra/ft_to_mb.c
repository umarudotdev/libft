/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_mb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2026/01/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * @brief Converts bytes to megabytes.
 *
 * @param bytes The number of bytes.
 * @return The equivalent number of megabytes (integer division).
 */
size_t	ft_to_mb(size_t bytes)
{
	return (bytes >> 20);
}
