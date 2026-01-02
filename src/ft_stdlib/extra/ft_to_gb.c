/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_gb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2026/01/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * @brief Converts bytes to gigabytes.
 *
 * @param bytes The number of bytes.
 * @return The equivalent number of gigabytes (integer division).
 */
size_t	ft_to_gb(size_t bytes)
{
	return (bytes >> 30);
}
