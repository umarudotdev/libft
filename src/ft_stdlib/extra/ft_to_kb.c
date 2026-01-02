/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_kb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2026/01/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * @brief Converts bytes to kilobytes.
 *
 * @param bytes The number of bytes.
 * @return The equivalent number of kilobytes (integer division).
 */
size_t	ft_to_kb(size_t bytes)
{
	return (bytes >> 10);
}
