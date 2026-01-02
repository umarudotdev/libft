/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2026/01/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * @brief Converts gigabytes to bytes.
 *
 * @param n The number of gigabytes.
 * @return The equivalent number of bytes.
 */
size_t	ft_gb(size_t n)
{
	return (n << 30);
}
